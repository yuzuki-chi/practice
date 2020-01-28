var cnt = 1;
while (true) {
    if (getParam('credit'+cnt)==null) break;
    // alert(getParam('credit'+cnt));

    if(Math.random()<=0.2) {
        //成功
        var p = document.getElementById("success_credit");
        //div
        var dev = document.createElement("dev");
        dev.innerText = getParam('credit'+cnt);
        // br
        var br = document.createElement("br");
        p.appendChild(dev);
        p.appendChild(br);

    } else { 
        //失敗
        var p = document.getElementById("faild_credit");
        //div
        var dev = document.createElement("dev");
        dev.innerText = getParam('credit'+cnt);
        // br
        var br = document.createElement("br");
        p.appendChild(dev);
        p.appendChild(br);
    }

    console.log(getParam('credit'+cnt));
    cnt++;
}

function getParam(name, url) {
    if (!url) url = window.location.href;
    name = name.replace(/[\[\]]/g, "\\$&");
    var regex = new RegExp("[?&]" + name + "(=([^&#]*)|&|#|$)"),
        results = regex.exec(url);
    if (!results) return null;
    if (!results[2]) return '';
    return decodeURIComponent(results[2].replace(/\+/g, " "));
}