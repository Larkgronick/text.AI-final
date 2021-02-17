// i was here
const allowedLength = 4;
const result = document.getElementById('result');
const list = document.getElementById('type-picker');
const listElements = list.querySelectorAll('li');
const captionFront = document.querySelector(".caption-front");
const captionBack = document.querySelector(".caption-back");
const scanAnimation = document.getElementById("scan-animation");
const checkArea = document.getElementById("check-area");
const checkResult = document.getElementById("check-result");
const checkButton = document.getElementById("send");
const backButton = document.getElementById("back-button");
const selectButton = document.getElementById("check-type");
const popupMessage = document.getElementById("popup-message")

// select check-type
listElements.forEach((element, index) => {
  element.innerHTML = `<img src="${element.getAttribute('data-thumbnail')}"/> <span>${element.innerText}</span>`;
  element.onclick = () => {
    list.style.display = 'none';
    selectButton.setAttribute('value', element.getAttribute('value'));
    selectButton.innerHTML = element.outerHTML;
  };
});

selectButton.innerHTML = listElements[0].outerHTML;
selectButton.setAttribute('value', listElements[0].getAttribute('value'));

selectButton.onclick = (e) => {
  e.preventDefault();
  list.style.display = list.style.display === 'block' ? 'none' : 'block';

};

//open result
checkButton.onclick = (e) => {
  e.preventDefault();
  let convertResult = parseInt(result.innerHTML);
  let action = selectButton.textContent.substring(1);
  if(action === 'Uniqueness'){
    if(isNaN(convertResult)){
      popupMessage.classList.add('show');
      popupMessage.innerText='Text is no provided!'
      setTimeout(function () {popupMessage.classList.remove('show')}, 3000);
    } else if(result.innerHTML.length < allowedLength){
      openResult(convertResult)
    } else {
      convertResult = 100;
      openResult(convertResult);
    } 
  } else {
    popupMessage.innerText='Action in developement. Please, try another one...'
    popupMessage.classList.add('show');
    setTimeout(function () {popupMessage.classList.remove('show')}, 3000);
  }
}

//back to main
backButton.onclick = (e) => {
  e.preventDefault();
  scanAnimation.classList.remove('active');
  captionBack.style.display = 'none';
  checkResult.style.display = 'none';
  captionFront.style.display = 'block';
  checkArea.style.display = 'flex';
}


function openResult(value){
  scanAnimation.classList.add('active');
  setTimeout(function(){
    showResult();
    setTimeout(animateValue("result", 0, value, 3000), 0);
  }, 3000);
}

function showResult(){
  captionBack.style.display = 'block';
  checkResult.style.display = 'flex';

  captionFront.style.display = 'none';
  checkArea.style.display = 'none';
}

function animateValue(id, start, end, duration) {
  if (start === end) return;
  let range = end - start;
  let current = start;
  let increment = end > start? 1 : -1;
  let stepTime = Math.abs(Math.floor(duration / range));
  let obj = document.getElementById(id);
  let timer = setInterval(function() {
      current += increment;
      obj.innerHTML = current;
      if (current == end) {
          clearInterval(timer);
      }
  }, stepTime);
}
