const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>AC</title>
</head>
<body>
    <h4>Kondisi</h4>  
    <p><button id='on'>Hidup</button></p>
    <p><button id='off'>Mati</button></p>
    <br>
    <form>
      <h4>Suhu</h4>  
      <select id='suhu' onchange="suhuR()">

      </select> 
    </form> 
  <script>
    //Suhu
    for(let i = 16; i<=30; i++){
       let pBaru = document.createElement('option');
       let teksBaru = document.createTextNode(String(i));
       pBaru.appendChild(teksBaru);
       pBaru.setAttribute('value', String(i));
       let sectionA = document.getElementById('suhu')
       sectionA.appendChild(pBaru);
     }

    function suhuR(){
        let temp = document.getElementById('suhu').value;
        var xhr = new XMLHttpRequest();
        var url = "/suhu";
        xhr.onreadystatechange = function() {
            if(this.onreadyState == 4  && this.status == 200) {
            console.log(xhr.responseText);
            }
        }
        xhr.open("POST", url, true);
        xhr.send(String(temp));
        xhr.onloadend = function(){
            console.log(xhr.status);
            if(this.status == 200) {
            var myObj = JSON.parse(this.responseText);
            console.log(myObj);
            }else{
            suhuR();
            }
        }
    }
     //on
    document.getElementById('on').addEventListener('click', on);
    function on(){
      var xhr = new XMLHttpRequest();
      var url = "/on";
      xhr.onreadystatechange = function() {
          if(this.onreadyState == 4  && this.status == 200) {
      console.log(xhr.responseText);
      }
    }
    xhr.open("POST", url, true);
    xhr.send(null);
    xhr.onloadend = function(){
        console.log(xhr.status);
        if(this.status == 200) {
        var myObj = JSON.parse(this.responseText);
        console.log(myObj);
        }else{
        on();
        }
    }
    }
    //of
    document.getElementById('off').addEventListener('click', off);
    function off(){
      var xhr = new XMLHttpRequest();
      var url = "/off";
      xhr.onreadystatechange = function() {
          if(this.onreadyState == 4  && this.status == 200) {
      console.log(xhr.responseText);
      }
    }
    xhr.open("POST", url, true);
    xhr.send(null);
    xhr.onloadend = function(){
        console.log(xhr.status);
        if(this.status == 200) {
        var myObj = JSON.parse(this.responseText);
        console.log(myObj);
        }else{
        off();
        }
    }
    }
  </script>
</body>
</html>
 )rawliteral";
