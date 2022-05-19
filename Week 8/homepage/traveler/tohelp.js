$(document).ready(function() {
    $('.tohelp').click(function() {
        window.location.href='help.html';
    });
    $('.tohelplight').click(function() {
        window.location.href='help.html';
        $('link[id="theme"]').attr('href', "styles-light.css");
    });
});