$(document).ready(function() 
{

    $('.correct').click(function()
    {
        $('.correct').css('background-color','#c6f8e2');
        $('#response1').text('Correct');
        $('#incorrect1').attr('disabled','disabled');
        $('#incorrect2').attr('disabled','disabled');
        $('#incorrect1').css('background-color','#d9edff');
        $('#incorrect2').css('background-color','#d9edff');
    });

    $('#incorrect1').click(function()
    {
        if($('#response1').text() != 'Correct')
        {
            $('#incorrect1').css('background-color','#ffd9d9');
            $('#response1').text('Incorrect');
        }
    });

    $('#incorrect2').click(function()
    {
        if($('#response1').text() != 'Correct')
        {
            $('#incorrect2').css('background-color','#ffd9d9');
            $('#response1').text('Incorrect');
        }
    });

    $('.submit').click(function()
    {
        var user_input = $('#user_input').val().toLowerCase();

        if(user_input === "yes")
        {
            $('#user_input').css('background-color','#c6f8e2');
            $('#user_input').attr('disabled','disabled');
            $('#response2').text('Correct');
            $('.submit').attr('disabled','disabled');
            $('.submit').css('background-color','#d9edff');
        }
        else //incorrect
        {
            if ($('#response2').text() != 'Correct')
            {
                $('#user_input').css('background-color','#ffd9d9');
                $('#response2').text('Incorrect');
            }
        }

    });

});