Module['readImage'] = (imageSource, imageWrapper) => {
  let canvas = Module._extractCanvasElement(imageSource);
  let imgData = canvas.getContext('2d').getImageData(
    0, 0, canvas.width, canvas.height);
  let heapBytes = Module._arrayToHeap(imgData.data);
  imageWrapper.rows = canvas.height;
  imageWrapper.cols = canvas.width;
  imageWrapper.size = imgData.data.length;
  imageWrapper.copyData(heapBytes.byteOffset);
  Module._freeArray(heapBytes);
};

Module['showImage'] = (canvasSource, imageWrapper) => {
  let canvas = Module._getCanvasElement(canvasSource)
  let imgData = new ImageData(new Uint8ClampedArray(
    imageWrapper.getData()), imageWrapper.cols, imageWrapper.rows);
  let ctx = canvas.getContext('2d');
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  canvas.width = imgData.width;
  canvas.height = imgData.height;
  ctx.putImageData(imgData, 0, 0);
};

Module['VideoCapture'] = function (videoSource) {
  let video = Module._getVideoElement(videoSource);
  let canvas = document.createElement('canvas');
  canvas.width = video.width;
  canvas.height = video.height;
  let ctx = canvas.getContext('2d');
  this.video = video;
  this.read = (imageWrapper) => {
    ctx.drawImage(video, 0, 0, video.width, video.height);
    imageWrapper.rows = video.height;
    imageWrapper.cols = video.width;
    let imgData = ctx.getImageData(0, 0, video.width, video.height);
    let heapBytes = Module._arrayToHeap(imgData.data);
    imageWrapper.size = imgData.data.length;
    imageWrapper.copyData(heapBytes.byteOffset);
    Module._freeArray(heapBytes);
  };
};

Module['_freeArray'] = (heapBytes) => {
  Module._free(heapBytes.byteOffset);
}

Module['_arrayToHeap'] = (typedArray) => {
  var numBytes = typedArray.length * typedArray.BYTES_PER_ELEMENT;
  var ptr = Module._malloc(numBytes);
  heapBytes = Module.HEAPU8.subarray(ptr, ptr + numBytes);
  heapBytes.set(typedArray);
  return heapBytes;
}

Module['_extractCanvasElement'] = (imageSource) => {
  let img = null;
  if (typeof imageSource === 'string') {
    img = document.getElementById(imageSource);
  } else {
    img = imageSource;
  }
  let canvas = null;
  if (img instanceof HTMLImageElement) {
    canvas = document.createElement('canvas');
    canvas.width = img.width;
    canvas.height = img.height;
    canvas.getContext('2d').drawImage(img, 0, 0, img.width, img.height);
  } else if (img instanceof HTMLCanvasElement) {
    canvas = img;
  } else {
    throw new Error('Please input the valid canvas or img id.');
  }
  return canvas;
}

Module['_getVideoElement'] = (videoSource) => {
  let video = null;
  if (typeof videoSource === 'string') {
    video = document.getElementById(videoSource);
  } else {
    video = videoSource;
  }
  if (!(video instanceof HTMLVideoElement)) {
    throw new Error('Please input the valid video element or id.');
  }
  return video;
}

Module['_getCanvasElement'] = (canvasSource) => {
  let canvas = null;
  if (typeof canvasSource === 'string') {
    canvas = document.getElementById(canvasSource);
  } else {
    canvas = canvasSource;
  }
  if (!(canvas instanceof HTMLCanvasElement)) {
    throw new Error('Please input the valid canvas element or id.');
  }
  return canvas;
}
