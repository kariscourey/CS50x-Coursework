// derived from https://stackoverflow.com/questions/23742344/run-script-before-iframe-loads

function loadScript(url, callback) 
{
    var script = document.createElement("script")
    script.type = "text/javascript";

    script.onload = function()
    {
        callback();
    };

  script.src = url;
  document.getElementsByTagName("body")[0].appendChild(script);

}

// call the function
loadScript('switch.js', function() 
{
  //executes after the script is loaded
  document.getElementById("fishy").src = "https://scratch.mit.edu/projects/654897803/embed"
});