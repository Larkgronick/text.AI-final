document.addEventListener("DOMContentLoaded", function () {

    const sendButton = document.getElementById('send') // button send
    sendButton.addEventListener('click', function () {
        let payload = 'name=' + encodeURIComponent(document.getElementById('value').value)

        const request = new XMLHttpRequest()
        request.open('POST', 'http://35.194.12.133:8080/cgi-bin/script.cgi', true)

        request.addEventListener('readystatechange', function () {
            document.querySelector("#img").classList.add('opacity');
            document.querySelector("#result").innerHTML = `${parseInt(request.responseText.replace(/[^\d]/g, ''))}`;
        })

        request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded')
        request.send(payload)
    })
})