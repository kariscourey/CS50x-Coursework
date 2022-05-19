$(document).ready(function() {
    $('.light').click(function() {
        $('link[id="theme"]').attr('href', "styles-light.css");
    });
    $('.dark').click(function() {
        $('link[id="theme"]').attr('href', "styles-dark.css");
    });
});