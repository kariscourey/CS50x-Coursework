function changeColor(event)
{
    var triggerObject = event.srcElement;
    document.getElementById('colorDiv').style.backgroundColor = triggerObject.innerHTL.toLowerCase()
}