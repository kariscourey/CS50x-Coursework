$(document).ready(function() 
{

    $('.tohelp').click(function() 
    {
        window.location.href='help.html';
    });


    $('.switch').click(function()
    {

        // my attempt: localStorage.dark = (JSON.parse(localStorage.dark) !== JSON.parse(localStorage.dark));
        localStorage.dark=(localStorage.dark=="true")?"false":"true"; //from https://stackoverflow.com/questions/63577939/save-dark-mode-light-mode-to-localstoage
        sessionStorage.switch_counter ++;

        if (localStorage.dark == 'true' && sessionStorage.switch_counter < 5)
        {
            $('link[id="theme"]').attr('href', "styles-dark.css");
            $('.switch').text('Light');
        }
        else if (localStorage.dark == 'false' && sessionStorage.switch_counter < 5)
        {
            $('link[id="theme"]').attr('href', "styles-light.css");
            $('.switch').text('Dark');
        }
        else
        {
            sessionStorage.switch_counter = 0;
            window.location.href='stop.html';
        }
    });

    $('.yes').click(function()
    {

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