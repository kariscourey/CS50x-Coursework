window.onload=function()
{
    if(localStorage.dark=='false')
    {
        $('link[id="theme"]').attr('href', "styles-light.css");
    }
    else
    {
        $('link[id="theme"]').attr('href', "styles-dark.css");
    }
}