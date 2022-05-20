window.onload=function()
{
    sessionStorage.setItem('switch_counter','0');

    if(localStorage.dark=='false')
    {
        $('link[id="theme"]').attr('href', "styles-light.css");
        $('.switch').text('Dark');
    }
    else
    {
        $('link[id="theme"]').attr('href', "styles-dark.css");
        $('.switch').text('Light');
    }
}