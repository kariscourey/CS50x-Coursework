$(document).ready(function() 
{

    $('.no').click(function() 
    {
        window.location.href='help.html';
    });

//need to decouple navigate and theme change!!
    $('.yes').click(function()
    {
        window.location.href='help.html';

        // my attempt: localStorage.dark = (JSON.parse(localStorage.dark) !== JSON.parse(localStorage.dark));
        localStorage.dark=(localStorage.dark=="true")?"false":"true"; //from https://stackoverflow.com/questions/63577939/save-dark-mode-light-mode-to-localstoage

        if (localStorage.dark == 'true')
        {
            $('link[id="theme"]').attr('href', "styles-dark.css");
        }
        else
        {
            $('link[id="theme"]').attr('href', "styles-light.css");
        }
    });

});