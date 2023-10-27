function change_p() {
    var r = document.getElementById("borderR").value;
    var g = document.getElementById("borderG").value;
    var b = document.getElementById("borderB").value;
    var wide = document.getElementById("wide").value;

    var color = "rgb(" + r + "," + g + "," + b + ")";
    var width = wide + "px";

    var change = document.getElementById("paragraph");
    change.style.borderColor = color;
    change.style.borderWidth = width;
}

function password() {
    var pw1 = document.getElementById("pw1").value;
    var pw2 = document.getElementById("pw2").value;

    if (pw1.length < 8) {
        alert("Password must be 8 characters or longer.");
    } else if(pw1 == pw2){
        alert("The two passwords match.");
    } else {
        alert("The passwords do not match.");
    }
}