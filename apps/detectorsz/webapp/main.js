"use strict";

const videoSrc = document.getElementById("videoSrc");
var streaming = false;
var frameIndex = 0;
var vc = null;
var filter = null;
var width = videoSrc.width;
var height = videoSrc.height;
var faceDetect = null;
const workloadName = "FACE_DETECT";
var datasetName = "";
var loop = null;
var totalTime = null;

function processVideo() {
  let t0 = performance.now();
  let src = vc.read();
  faceDetect.faceDetectWithLog(src);
  Module.showImage('videoProcessed', src);
  src.delete();
  let t1 = performance.now();
  faceDetect.updateTotalTime(frameIndex, t1 - t0);
  frameIndex++;
  requestAnimationFrame(processVideo);
}

function stopVideo() {
  if (!streaming) return;
  totalTime = performance.now() - totalTime;
  saveLogs();
  frameIndex = 0;
  stopVideoProcessing();
  document.getElementById("videoProcessed")
    .getContext("2d").clearRect(0, 0, width, height);
  streaming = false;
}

function stopVideoProcessing() {
  if (faceDetect != null && !faceDetect.isDeleted()) {
    faceDetect.delete();
  }
  //clearInterval(loop);
}

function startVideoProcessing() {
  if (!streaming) {
    console.warn("Please select the video.");
    return;
  }
  stopVideoProcessing();
  faceDetect = new Module.FaceDetect(datasetName);
  totalTime = performance.now();
  videoSrc.play();
  //loop = setInterval(processVideo, 33);
  requestAnimationFrame(processVideo);
}

const showMessage = (message, isError) => {
  var element = document.getElementById('message')
  element.innerHTML = message
  element.className = isError ? 'error' : 'info'
}

const playSelectedFile = function (event) {
  let file = this.files[0]
  let type = file.type
  datasetName = file.name.substring(0, file.name.lastIndexOf('.'));
  let videoNode = document.getElementById('videoSrc')
  let canPlay = videoNode.canPlayType(type)
  if (canPlay === '') canPlay = 'no'
  let message = 'Can play type "' + type + '": ' + canPlay
  let isError = canPlay === 'no'
  showMessage(message, isError)
  if (isError) {
    return
  }
  let fileURL = URL.createObjectURL(file)
  videoNode.src = fileURL
}

const saveLogs = () => {
  let resLabel = document.getElementById('rolutionLabel').textContent;
  let system = getSystemName();
  let head = ",system,resolution_label";
  let columns = "," + getSystemName() + "," + resLabel;
  let reportName = "LOG_" + workloadName + "_" + datasetName + "_" +
    resLabel + "_" + system;
  let logData = new Blob(
    [faceDetect.logsToStringAndAddCommon(head, columns)],
    { type: 'application/csv' });
  let elemA = document.createElement('a');
  elemA.style.display = 'none';
  elemA.download = reportName + ".csv";
  elemA.href = URL.createObjectURL(logData)
  document.body.appendChild(elemA);
  elemA.click();
  document.body.removeChild(elemA);
  let metaLog = "workload,dataset,resolution,system,total_frames,"
    + "total_frames_processeds,test_total_time_ms,log_file\n";
  metaLog = metaLog + workloadName + "," + datasetName
    + "," + resLabel + "," + system + ",0," + frameIndex
    + "," + totalTime + "," + reportName + ".csv";
  let metaLogData = new Blob([metaLog], { type: 'application/csv' });
  let elemB = document.createElement('a');
  elemB.style.display = 'none';
  elemB.download = "META_" + reportName + ".csv";
  elemB.href = URL.createObjectURL(metaLogData)
  document.body.appendChild(elemB);
  elemB.click();
}

function getSystemName() {
  let name = "Web"
  let osName = "Unknown OS";
  if (navigator.appVersion.indexOf("Win") != -1) osName = "Windows";
  if (navigator.appVersion.indexOf("Mac") != -1) osName = "MacOS";
  if (navigator.appVersion.indexOf("X11") != -1) osName = "UNIX";
  if (navigator.appVersion.indexOf("Linux") != -1) osName = "Linux";

  if (navigator.userAgent.indexOf('Firefox') > 0) {
    name = navigator.userAgent.substring(
      navigator.userAgent.indexOf("Firefox"),
      navigator.userAgent.indexOf("Firefox") + 10).replace("/", "_");
  } else if (navigator.userAgent.indexOf('Chrome') > 0) {
    name = navigator.userAgent.substring(
      navigator.userAgent.indexOf("Chrome"),
      navigator.userAgent.indexOf("Chrome") + 9)
      .replace("/", "_");
  }
  return name + "_" + osName;
}

const init = () => {
  console.log("TCC WASM - João Lourenço Souza Jr");

  if (streaming) return;

  let inputFile = document.getElementById('inputFile')
  inputFile.addEventListener('change', playSelectedFile, false);

  videoSrc.addEventListener("canplay", function (ev) {
    if (!streaming) {
      streaming = true;
      vc = new Module.VideoCapture(videoSrc);
    }
    startVideoProcessing();
  }, false);

  videoSrc.addEventListener("ended", function (ev) {
    stopVideo();
  }, false);
};

var Module = {
  preRun: [],
  postRun: [init],
  print: function (text) {
    if (arguments.length > 1) text = Array.prototype.slice.call(arguments).join(' ');
    console.log(text);
  },
  printErr: function (text) {
    if (arguments.length > 1) text = Array.prototype.slice.call(arguments).join(' ');
    console.error(text);
  },
};
