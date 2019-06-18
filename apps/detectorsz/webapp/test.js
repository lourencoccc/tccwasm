"use strict";

const videoSrc = document.getElementById("videoSrc");
var streaming = false;
var frameIndex = 0;
var vc = null;
var filter = null;
var width = videoSrc.width;
var height = videoSrc.height;
var faceDetect = null;
var workloadName = "";
var loop = null;

function processVideo() {
  let t0 = performance.now();
  let src = vc.read();
  faceDetect.faceDetectWithLog(src);
  Module.showImage('videoProcessed', src);
  src.delete();
  let t1 = performance.now();
  faceDetect.updateTotalTime(frameIndex, t1 - t0);
  frameIndex++;
  //requestAnimationFrame(processVideo);
}

function stopVideo() {
  if (!streaming) return;
  frameIndex = 0;
  saveLogs();
  stopVideoProcessing();
  document.getElementById("videoProcessed")
    .getContext("2d").clearRect(0, 0, width, height);
  streaming = false;
}

function stopVideoProcessing() {
  if (faceDetect != null && !faceDetect.isDeleted()) {
    faceDetect.delete();
  }
  clearInterval(loop);
}

function startVideoProcessing() {
  if (!streaming) {
    console.warn("Please select the video.");
    return;
  }
  stopVideoProcessing();
  faceDetect = new Module.FaceDetect(workloadName);
  videoSrc.play();
  loop = setInterval(processVideo, 1000/24);
  //requestAnimationFrame(processVideo);
}

const showMessage = (message, isError) => {
  var element = document.getElementById('message')
  element.innerHTML = message
  element.className = isError ? 'error' : 'info'
}

const playSelectedFile = function (event) {
  let file = this.files[0]
  let type = file.type
  workloadName = file.name.substring(0, file.name.lastIndexOf('.'));
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
  let logData = new Blob(
    [faceDetect.logsToStringAndAddCommon("","")], { type: 'application/csv' });
  let elemA = document.createElement('a');
  elemA.style.display = 'none';
  elemA.download = workloadName + ".csv";
  elemA.href = URL.createObjectURL(logData)
  document.body.appendChild(elemA);
  elemA.click();
  document.body.removeChild(elemA);
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
