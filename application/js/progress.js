                    function addUpMarkBoxes() 
                    {
                        var marks=0;
                    var totalweighting=0;
                    var output="";
                    for(j=0;j<document.progress.elements.length;j++)
                    {
                        var formObj=document.progress.elements[j];
                        if (formObj.type.toLowerCase() == "text")
                        {
                            if (isFinite(parseFloat(formObj.value)))
                            {
                                var formTotal=document.progress.elements[j+1];
                                var formWeighting=document.progress.elements[j-1];
                                totalweighting=totalweighting+parseFloat(formWeighting.value);
                                marks=marks+(parseFloat(formObj.value)/parseFloat(formTotal.value)*parseFloat(formWeighting.value));
                            }
                        }
                    }
                    
                    document.progress.totalmarks1.value=parseFloat(marks/totalweighting*100);
                    document.progress.totalmarks2.value=parseFloat(marks/totalweighting*100);
                    
                    if (marks>totalweighting)
                    {
                        document.progress.markstotal1.value="Error with marks total.";
                        document.progress.markstotal2.value="Error with marks total.";
                        return false;
                    } 
                    return true;
                }
                function altervalues()
                {
                    document.progress.markstotal1.value="Feedback not saved!!!!"
                    document.progress.markstotal2.value="Feedback not saved!!!!";         
                } 
                function saveDetails(form)
                {
                    if (addUpMarkBoxes())
                    {
                        if(confirm("Save Changes: Please note that pressing CANCEL will lose change made!!")){
                            document.progress.savechangesdialog.value="Yes";
                            form.submit();
                        }
                    }
                }
