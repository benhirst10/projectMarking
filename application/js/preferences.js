 function checkradio() {
    var radio_choice1 = -1;
    var radio_choice2 = -1;
    var radio_choice3 = -1;
    var radio_choice4 = -1;
    var msgdisp = false;
    var firstChoiceSup = -1;
    var secondChoiceSup = -1;
    var thirdChoiceSup = -1;
    var fourthChoiceSup = -1;
    var s1 = 0;
    var s2 = 0;
    var s3 = 0;
    var s4 = 0;
    var s5 = 0;
    var s6 = 0;

    var posRadio=0;

    for (i=0;i<document.projectform.length;i++)
    {
        var tempobj=document.projectform.elements[i];
        if (tempobj.type==\"radio\" && posRadio==0)
        {
            posRadio=i;
        }
    }


    // Loop from zero to the one minus the number of radio button selections
    for (counter = 0; counter < document.projectform.colfirstchoice.length; counter++)
    {
        if (document.projectform.colfirstchoice[counter].checked)
        {
            radio_choice1 = counter;
            firstChoiceSup=counter;
        }
    }
    for (counter = 0; counter < document.projectform.colsecondchoice.length; counter++)
    {
        if (document.projectform.colsecondchoice[counter].checked)
        {
            radio_choice2 = counter;
            secondChoiceSup=counter;
        }
    }

    for (counter = 0; counter < document.projectform.colthirdchoice.length; counter++)
    {
        if (document.projectform.colthirdchoice[counter].checked)
        {
            radio_choice3 = counter;
            thirdChoiceSup=counter;
        }
    }

    for (counter = 0; counter < document.projectform.colfourthchoice.length; counter++)
    {
        if (document.projectform.colfourthchoice[counter].checked)
        {
            radio_choice4 = counter;
            fourthChoiceSup=counter;
        }
    }


    if (radio_choice1!=-1)
    {
        if (radio_choice1==radio_choice2 || radio_choice1==radio_choice3 || radio_choice1==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the first \");
            return false;
        }


    }

    if (radio_choice2!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice2 || radio_choice2==radio_choice3 || radio_choice2==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the second\");
            return false;
        }

    }

    if (radio_choice3!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice3 || radio_choice2==radio_choice3 || radio_choice3==radio_choice4)
        {
        alert (\"Please make sure that preferences are for a different project rather than the same as the third\");
        return false;
        }

    }

    if (radio_choice4!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice4 || radio_choice2==radio_choice4 || radio_choice3==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the fourth\");
            return false;
        }

    }

    return true;


    }
    function checkformradio() {
    var radio_choice1 = -1;
    var radio_choice2 = -1;
    var radio_choice3 = -1;
    var radio_choice4 = -1;
    var msgdisp = false;
    var firstChoiceSup = -1;
    var secondChoiceSup = -1;
    var thirdChoiceSup = -1;
    var fourthChoiceSup = -1;
    var s1 = 0;
    var s2 = 0;
    var s3 = 0;
    var s4 = 0;
    var s5 = 0;
    var s6 = 0;

    var posRadio=0;


    for (i=0;i<document.projectform.length;i++)
    {
        var tempobj=document.projectform.elements[i];
        if (tempobj.type==\"radio\" && posRadio==0)
        {
            posRadio=i;
        }
    }


    // Loop from zero to the one minus the number of radio button selections
    for (counter = 0; counter < document.projectform.colfirstchoice.length; counter++)
    {
        if (document.projectform.colfirstchoice[counter].checked)
        {
            radio_choice1 = counter;
            firstChoiceSup=counter;
        }
    }
    for (counter = 0; counter < document.projectform.colsecondchoice.length; counter++)
    {
        if (document.projectform.colsecondchoice[counter].checked)
        {
            radio_choice2 = counter;
            secondChoiceSup=counter;
        }
    }

    for (counter = 0; counter < document.projectform.colthirdchoice.length; counter++)
    {
        if (document.projectform.colthirdchoice[counter].checked)
        {
            radio_choice3 = counter;
            thirdChoiceSup=counter;
        }
    }

    for (counter = 0; counter < document.projectform.colfourthchoice.length; counter++)
    {
        if (document.projectform.colfourthchoice[counter].checked)
        {
            radio_choice4 = counter;
            fourthChoiceSup=counter;
        }
    }


    if (radio_choice1!=-1)
    {
        if (radio_choice1==radio_choice2 || radio_choice1==radio_choice3 || radio_choice1==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the first\");
            return false;
        }


    }

    if (radio_choice2!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice2 || radio_choice2==radio_choice3 || radio_choice2==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the second\");
            return false;
        }

    }

    if (radio_choice3!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice3 || radio_choice2==radio_choice3 || radio_choice3==radio_choice4)
        {
        alert (\"Please make sure that preferences are for a different project rather than the same as the third\");
        return false;
        }

    }

    if (radio_choice4!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice4 || radio_choice2==radio_choice4 || radio_choice3==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the fourth\");
            return false;
        }

    }

    if (radio_choice1==-1 || radio_choice2==-1 || radio_choice3==-1 || radio_choice4==-1)
    {
        alert (\"Not all choices have been made\");
        return false;
    }


    return true;


    }