function init(a) {
    initTHREE("canvasdiv", a)
}
var camera, scene, renderer, container, controller;
var fov = 45.0;
var near = 0.1;
var far = 1000;
var matcap1, matcap2;

function initTHREE(a, b) {
    container = document.getElementById(a);
    var w = container.offsetWidth;
    var h = container.offsetHeight;
    renderer = new THREE.WebGLRenderer({
        antialias: true
    });
    renderer.setPixelRatio(window.devicePixelRatio);
    renderer.setSize(w, h);
    renderer.setClearColor(0xffffff);
    container.appendChild(renderer.domElement);
    renderer.toneMapping = THREE.LinearToneMapping;
    renderer.toneMappingExposure = 1.0;
    renderer.gammaOutput = true;
    scene = new THREE.Scene;
    camera = new THREE.PerspectiveCamera(fov, w / h, near, far);    
    camera.position.z = 120;
    camera.position.y = 0;
    camera.position.x = 0;
    camera.lookAt(scene.position);
    controls = new THREE.OrbitControls(camera, renderer.domElement);
    controls.minDistance = 38;
    controls.maxDistance = 400;
    var c = new THREE.LoadingManager(render);
    var d = new THREE.TextureLoader(c);
    var e = mainbasepath + "/textures/matcaps/matcap-porcelain-white.jpg";
    matcap1 = d.load(e, function() {
        matcap1.encoding = THREE.sRGBEncoding
    });
    var f = mainbasepath + "/textures/matcaps/matcap-porcelain-red.jpg";
    matcap2 = d.load(f, function() {
        matcap2.encoding = THREE.sRGBEncoding
    });
    loaderJSON(b);
    window.addEventListener('resize', windowResize, false);
    render()
}

function render() {
    controls.update();
    renderer.render(scene, camera)
}

function animate() {
    requestAnimationFrame(animate);
    controls.update();
    renderer.render(scene, camera)
}

function addModel(a) {
    loaderModel(a)
}

function windowResize() {
    var w = container.offsetWidth;
    var h = container.offsetHeight;
    camera.aspect = w / h;
    camera.updateProjectionMatrix();
    renderer.setSize(w, h)
}
var yaStart = 0;
var yaEnd = 0;
var endType = "";
var timeDelay = 1000;
var hasdown1 = 0;
var hasdown2 = 0;
var hasdown3 = 0;
var toothDepthMesh, toothSpecularMesh, toothMeshAry = [];
var isNull = 0;
var sceneA = [];
var sce = function() {
    return {
        sceneNum: 0,
        sc: []
    }
};
var matrix = function() {
    return {
        mat: [],
        num: 0
    }
};
var upTooth = [];
var upToothLength = 0;
var downTooth = [];
var downToothLength = 0;
var toothTotal = 28;

function loaderJSON(a) {
    $.getJSON(a.mangerJsonPath, function(a) {
        toothTotal = a.toothTotal;
        yaEnd = a.step - 1;
        upTooth = a.up;
        upToothLength = upTooth.length;
        downTooth = a.down;
        downToothLength = downTooth.length
    });
    $.getJSON(a.jsonPath, function(b) {
        var d = 0;
        $.each(b, function(a, b) {
            var c = sce();
            $.each(b, function(a, b) {
                var d = matrix();
                d.num = b.Tooth;
                var e = 0;
                $.each(b.Matrix, function(a, b) {
                    d.mat[e] = b;
                    e++
                });
                c.sc[a] = d
            });
            c.sceneNum = d;
            sceneA[d] = c;
            d++
        });
        addModel(a)
    })
}
var mainbasepath = "";

function loaderModel(a) {
    function b(b, c) {
        e.load(mainbasepath, a.downpath + "/" + b + c, function(a) {
            makeDownGumMesh(a, b);
            checkFinish()
        }, {
            useWorker: !0
        })
    }

    function d(b, c) {
        e.load(mainbasepath, a.uppath + "/" + b + c, function(a) {
            makeUpGumMesh(a, b);
            checkFinish()
        }, {
            useWorker: !0
        })
    }

    function c(b, c) {
        e.load(mainbasepath, a.toothpath + "/" + b + c, function(a) {
            toothMeshAry[b] = a.clone();
            isNull++;
            isNull == toothTotal && addToothMesh()
        }, {
            useWorker: !0
        })
    }
    for (var e = new THREE.CTMLoader, f = yaStart; f < yaEnd + 1; f++) b(f, ".ctm");
    for (f = yaStart; f < yaEnd + 1; f++) d(f, ".ctm");
    for (f = 0; f < toothTotal; f++) c(f, ".ctm")
}

function addToothMesh() {
    for (var a = yaStart; a < yaEnd + 1; a++) {
        var b = sceneA[a],
            d = a,
            c = b;
        b = b ? b.sc.length : toothTotal;
        for (var e = 0; e < toothTotal; e++) {
            var f = [];
            if (c)
                for (var g = 0; g < b; g++) {
                    var h = c.sc[g];
                    if (h.num == e) {
                        f = h.mat;
                        break
                    }
                }
            makeToothMesh(e, toothMeshAry[e], d, f)
        }
        checkFinish()
    }
}

function makeUpGumMesh(a, b) {
    var c = new THREE.Mesh(a);
    c.position.y -= 5;
    c.name = "up" + b;
    c.material = new THREE.MeshMatcapMaterial({
        color: 0xffffff,
        matcap: matcap2
    });
    scene.add(c);
    hasdown1 += 1
}

function makeDownGumMesh(a, b) {
    var c = new THREE.Mesh(a);
    c.position.y -= 5;
    c.name = "down" + b;
    c.material = new THREE.MeshMatcapMaterial({
        color: 0xffffff,
        matcap: matcap2
    });
    scene.add(c);
    hasdown2 += 1
}

function makeToothMesh(a, b, c, d) {
    var e = new THREE.Matrix4;
    e.set(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8], d[9], d[10], d[11], d[12], d[13], d[14], d[15]);
    var f = new THREE.Mesh(b);
    f.applyMatrix(e);
    f.position.y -= 5;
    var g = "";
    for (var i = 0; i < upToothLength; i++) {
        if (upTooth[i] == a) {
            g = "upTooth";
            break
        }
    }
    if ("" == g) {
        for (var i = 0; i < downToothLength; i++) {
            if (downTooth[i] == a) {
                g = "downTooth";
                break
            }
        }
    }
    f.name = g + c;
    f.material = new THREE.MeshMatcapMaterial({
        color: 0xffffff,
        matcap: matcap1
    });
    scene.add(f);
    hasdown3 += 1
}

function checkFinish() {
    if ((hasdown1 == (yaEnd - yaStart + 1)) && (hasdown2 == (yaEnd - yaStart + 1)) && (hasdown3 == toothTotal * (yaEnd - yaStart + 1))) {
        initControl();
        playOrStop()
    }
}
playNow = yaStart - 1;
var jindu;
var isXuanHuan = false;

function initControl() {
    document.getElementById("hide").style.display = "none";
    document.getElementById("playorstop").disabled = false;
    document.getElementById("jindutiao").disabled = false;
    document.getElementById("xunhuan").disabled = false;
    document.getElementById("exportgif").disabled = false;
    document.getElementById("exportgif").addEventListener("click", exportGif);
    document.getElementById("playorstop").addEventListener("click", function() {
        document.getElementById("playorstop").style.display = "none";
        document.getElementById("stop").style.display = "block";
        playOrStop()
    });
    document.getElementById("stop").addEventListener("click", function() {
        document.getElementById("playorstop").style.display = "block";
        document.getElementById("stop").style.display = "none";
        playOrStop()
    });
    jindu = document.getElementById("jindutiao");
    jindu.oninput = onChangeJindu;
    jindu.min = yaStart;
    jindu.max = yaEnd;
    document.getElementById("xunhuan").addEventListener("click", function() {
        setIsXunHuan()
    });
    setIsXunHuan(!1);
    document.getElementById("front").addEventListener("click", function() {
        front()
    });
    document.getElementById("left").addEventListener("click", function() {
        left()
    });
    document.getElementById("right").addEventListener("click", function() {
        right()
    });
    document.getElementById("top").addEventListener("click", function() {
        up()
    });
    document.getElementById("bottom").addEventListener("click", function() {
        bottom()
    });
    document.getElementById("front2").addEventListener("click", function() {
        front2()
    });
    document.getElementById("back2").addEventListener("click", function() {
        back2()
    });
    showStep(0);
    animate()
}

function setIsXunHuan(t) {
    if (t === undefined) {
        isXuanHuan = !isXuanHuan
    } else {
        isXuanHuan = t
    }
    document.getElementById("xunhuan").checked = isXuanHuan
}

function playGo() {
    playNow += 1;
    console.log(playNow);
    console.log(yaEnd);
    if (playNow > yaEnd) {
        if (isXuanHuan === true) {
            playNow = yaStart - 1
        } else {
            stopPlay();
            playNow = yaStart - 1
        }
    } else {
        showStep(playNow)
    }
}
var isPlaying = true;
var atimer;

function playOrStop() {
    if (isPlaying) {
        stopPlay()
    } else {
        isPlaying = true;
        atimer = window.setInterval(playGo, timeDelay)
    }
}

function stopPlay() {
    document.getElementById("playorstop").style.display = "block";
    document.getElementById("stop").style.display = "none";
    isPlaying = false;
    try {
        window.clearInterval(atimer)
    } catch (error) {}
}

var isExportingGif = false;

function exportGif() {
    if (isExportingGif || typeof GIF === "undefined") {
        return
    }

    isExportingGif = true;
    stopPlay();

    var button = document.getElementById("exportgif");
    var status = document.getElementById("exportstatus");
    var previousStep = Number(jindu.value);
    var sourceCanvas = renderer.domElement;
    var outputWidth = Math.min(640, sourceCanvas.width);
    var outputHeight = Math.round(outputWidth * sourceCanvas.height / sourceCanvas.width);
    var frameCanvas = document.createElement("canvas");
    var frameContext = frameCanvas.getContext("2d");
    frameCanvas.width = outputWidth;
    frameCanvas.height = outputHeight;

    button.disabled = true;
    button.textContent = "正在生成...";
    status.textContent = "";

    var gif = new GIF({
        workers: 2,
        quality: 10,
        width: outputWidth,
        height: outputHeight,
        repeat: 0,
        background: "#ffffff",
        workerScript: "web/js/libs/gif.worker.js"
    });

    for (var frame = yaStart; frame <= yaEnd; frame++) {
        showStep(frame);
        renderer.render(scene, camera);
        frameContext.clearRect(0, 0, outputWidth, outputHeight);
        frameContext.drawImage(sourceCanvas, 0, 0, outputWidth, outputHeight);
        gif.addFrame(frameContext, {
            copy: true,
            delay: 700
        });
    }

    gif.on("finished", function(blob) {
        var url = URL.createObjectURL(blob);
        var link = document.createElement("a");
        link.href = url;
        link.download = "ortho-animation.gif";
        document.body.appendChild(link);
        link.click();
        link.remove();
        window.setTimeout(function() {
            URL.revokeObjectURL(url)
        }, 1000);
        showStep(previousStep);
        button.disabled = false;
        button.textContent = "保存 GIF";
        status.textContent = "已下载";
        isExportingGif = false
    });

    gif.render()
}

var display = 0;

function showStep(i) {
    jindu.value = i;
    scene.children.forEach(function(a) {
        if (a.type == "Mesh") {
            if (display == 0) {
                if (a.name == "upTooth" + i || a.name == "downTooth" + i) {
                    a.visible = true
                } else {
                    if (a.name == "up" + i || a.name == "down" + i) {
                        a.visible = true
                    } else {
                        a.visible = false
                    }
                }
            } else if (display == 1) {
                if (a.name == "upTooth" + i) {
                    a.visible = true
                } else {
                    if (a.name == "up" + i) {
                        a.visible = true
                    } else {
                        a.visible = false
                    }
                }
            } else if (display == 2) {
                if (a.name == "downTooth" + i) {
                    a.visible = true
                } else {
                    if (a.name == "down" + i) {
                        a.visible = true
                    } else {
                        a.visible = false
                    }
                }
            }
        }
    })
}

function onChangeJindu() {
    stopPlay();
    showStep(jindu.value)
}

function front() {
    0 != display && (display = 0, showStep(jindu.value));
    camera.position.z = 120;
    camera.position.y = 0;
    camera.position.x = 0;
    camera.lookAt(scene.position);
    camera.updateProjectionMatrix()
}

function left() {
    0 != display && (display = 0, showStep(jindu.value));
    camera.position.z = 0;
    camera.position.y = 0;
    camera.position.x = 120;
    camera.lookAt(scene.position);
    camera.updateProjectionMatrix()
}

function right() {
    0 != display && (display = 0, showStep(jindu.value));
    camera.position.z = 0;
    camera.position.y = 0;
    camera.position.x = -120;
    camera.lookAt(scene.position);
    camera.updateProjectionMatrix()
}

function up() {
    var a = jindu.value;
    display = 1;
    showStep(a);
    camera.position.z = 0;
    camera.position.y = -120;
    camera.position.x = 0;
    camera.lookAt(scene.position);
    camera.updateProjectionMatrix()
}

function bottom() {
    var a = jindu.value;
    display = 2;
    showStep(a);
    camera.position.z = 0;
    camera.position.y = 120;
    camera.position.x = 0;
    camera.lookAt(scene.position);
    camera.updateProjectionMatrix()
}

function front2() {
    stopPlay();
    var a;
    if (jindu.value == jindu.min) {
        a = jindu.min
    } else {
        a = jindu.value;
        a--
    }
    showStep(a)
}

function back2() {
    stopPlay();
    var a;
    if (jindu.value == jindu.max) {
        a = jindu.max
    } else {
        a = jindu.value;
        a++
    }
    showStep(a)
};
