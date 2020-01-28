var btn = document.getElementById("add_credit");
var input_cnt = 1;
btn.addEventListener("click", function(){
    // <p>
    var p = document.getElementById("input_credit");
 
    //div
    var dev = document.createElement("dev");
    input_cnt = input_cnt+1;
    dev.innerText = "単位名"+ input_cnt +"：";

    //input
    var input = document.createElement("input");
    input.DOCUMENT_TYPE_NODE = "text";
    input.name = "credit"+input_cnt;
    input.id = "credit"+input_cnt;
    input.size = "50";

    // br
    var br = document.createElement("br");

    p.appendChild(dev);
    p.appendChild(input);
    p.appendChild(br);
}, false);

// "<input type='text' name='credit001' id='credit001' size='50'><br/>"