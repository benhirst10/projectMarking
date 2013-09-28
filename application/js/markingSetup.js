
  function displayOwnProjectDiv(divname,selectname)
  {
  
    if (document.markingSetup.elements[selectname].options[document.markingSetup.elements[selectname].selectedIndex].value=="own project")
    {
        document.getElementById(divname).style.display='block';
    
    } else document.getElementById(divname).style.display='none';
  } 



  function countSupervisorSecondMarker() 
        {
            var returnVal=true;  
            var hiddenStart=0;
            var selectStart=0;
            for (i=0;i<document.markingSetup.length;i++)
            {
               var tempobj=document.markingSetup.elements[i];
               if (tempobj.type=="hidden")
               {
                   if (tempobj.name.substr(0,3)=="sm_") 
                   {
                         document.markingSetup.elements[i-1].value=0;
                         tempobj.value=0;
                   }
           
                   if (tempobj.name.substr(0,5)=="proj[")
                   {
                         document.markingSetup.elements[i].value=0;
                   }    
                   
                   if (hiddenStart==0  && tempobj.name.substr(0,3)=="sm_") hiddenStart=i-1;
                }
                
                if (tempobj.type=="select-one" && selectStart==0) selectStart=i;
                if (tempobj.type=="textarea") document.markingSetup.elements[i].value="";
        
        
             }
        var smNoneAlloc=0;
        var supNoneAlloc=0;
        var smTotalAlloc=0;
        var supTotalAlloc=0;    
        var studentCount=0;
        for (i=0;i<hiddenStart+1;i++)
        {
            var tempobj=document.markingSetup.elements[i];
            var tempobj2=document.markingSetup.elements[i+1];
            var tempobj3=document.markingSetup.elements[i+2];
            if (tempobj.name.substr(0,14)=="markerSelected") ++studentCount;
            if (tempobj.name.substr(0,14)=="markerSelected" && tempobj.type=="hidden") 
            {
                var supervisor = tempobj.value;
        var secondmarkerID = "";
                if (supervisor!="" && document.markingSetup.elements[supervisor]!=undefined)
                {
                     document.markingSetup.elements[supervisor].value++;
                     supNoneAlloc++;                
                }
                if (tempobj2.name.substr(0,20)=="secondMarkerSelected" && tempobj2.type=="hidden") 
                {
                    var secondmarker = "sm_"+tempobj2.value;
                    if (secondmarker!="sm_" && document.markingSetup.elements[secondmarker]!=undefined)
                    {
                        document.markingSetup.elements[secondmarker].value++;
            secondmarkerID=tempobj2.value;
                        supNoneAlloc++;                
                    }
                }                   
                var supervisorproj="proj["+supervisor+"]["+tempobj3.value+"]";
                var secondmarkerproj="proj["+secondmarkerID+"]["+tempobj3.value+"]";                
                if (supervisorproj!="proj[][]" && document.markingSetup.elements[supervisorproj]!=undefined)
                    document.markingSetup.elements[supervisorproj].value++;             
                if (secondmarkerproj!="proj[][]" && document.markingSetup.elements[secondmarkerproj]!=undefined)
                    document.markingSetup.elements[secondmarkerproj].value++;               
            }
        
            
            if (tempobj.type=="select-one" && tempobj.options[tempobj.selectedIndex].value!="Select Choice")
            {
              var supervisor = tempobj.options[tempobj.selectedIndex].value;
              var secondmarkerID = "";
              if (supervisor!="" && document.markingSetup.elements[supervisor]!=undefined)
              {
                     document.markingSetup.elements[supervisor].value++;
                     supNoneAlloc++;
                    
              } 
//            alert(supervisor);
           
             if (tempobj2.type=="select-one" && tempobj2.options[tempobj2.selectedIndex].value!="Select Choice")
             {
                  var secondmarker = "sm_"+tempobj2.options[tempobj2.selectedIndex].value;
                  secondmarkerID=tempobj2.options[tempobj2.selectedIndex].value;
                  if (secondmarker!="sm_" && document.markingSetup.elements[secondmarker]!=undefined)
                  {
                         document.markingSetup.elements[secondmarker].value++;
                         smNoneAlloc++;
                     
                  }
                     
              }
             if (tempobj3.type=="select-one" && tempobj3.options[tempobj3.selectedIndex].value!="Select Choice")
             {
               var supervisorproj="proj["+supervisor+"]["+tempobj3.options[tempobj3.selectedIndex].value+"]";
               var secondmarkerproj="proj["+secondmarkerID+"]["+tempobj3.options[tempobj3.selectedIndex].value+"]";
              // alert(supproj);
               if (supervisorproj!="proj[][]" && document.markingSetup.elements[supervisorproj]!=undefined)
                document.markingSetup.elements[supervisorproj].value++;
               if (secondmarkerproj!="proj[][]" && document.markingSetup.elements[secondmarkerproj]!=undefined)
                    document.markingSetup.elements[secondmarkerproj].value++;    
               
             }
             i=i+2;
            }
            if (tempobj.type=="select-one") {supTotalAlloc++;smTotalAlloc++;}
        }
        supNoneAlloc=supTotalAlloc-supNoneAlloc;    
        smNoneAlloc=smTotalAlloc-smNoneAlloc;
        var message="<uid>:<supervisor>:<2nd_Marker> ";
        var cnt=1;
        var oRed = '#ff0000';
        var supervisorCountOver=0;
        var smCountOver=0;
        var supervisorCountUnder=0;
        var supTCount=0;
        var smTCount=0;
        var smCountUnder=0;     

        for (i=hiddenStart;i<document.markingSetup.length;i++)
        {
            var tempobj=document.markingSetup.elements[i];
            if (tempobj.type=="hidden")
        {
            if (tempobj.name.substr(0,5)=="proj[") 
            {
                var projname=tempobj.name;
                var projname=projname.split("[");
                
                var temp1 = new String(projname[1]);
                temp1=temp1.split("]");
                var markerId=""+temp1[0];
                
                var temp2= new String(projname[2]);
                temp2=temp2.split("]");
                var projid=""+temp2[0];
                
                var projDisp="projectDisp["+projid+"]";
                if (document.markingSetup.elements[projDisp]!=undefined && parseInt(tempobj.value)>0) 
                    document.markingSetup.elements[projDisp].value=document.markingSetup.elements[projDisp].value+markerId+":"+tempobj.value+" ";
            }
        
            if (cnt%2>0 && tempobj.name.substr(0,5)!="proj[") 
            {
                message=message+tempobj.name+":"+parseFloat(tempobj.value);
                var supervisor="supT["+tempobj.name+"]";
                var supervisorDisp="supDisp["+tempobj.name+"]";
                if (document.markingSetup.elements[supervisor]!=undefined)
                {
                    if (parseInt(tempobj.value)>parseInt(document.markingSetup.elements[supervisor].value)) 
                    {
                        var needs=parseInt(tempobj.value)-parseInt(document.markingSetup.elements[supervisor].value);
                        message=message+"(-"+needs+"!!)";
                        document.markingSetup.elements[supervisorDisp].value="-"+needs+"!!";
                        supervisorCountOver+=needs;
                        retrunVal=false;
                    }
                    if (parseInt(tempobj.value)<=parseInt(document.markingSetup.elements[supervisor].value))
                    {
                        var needs=parseInt(document.markingSetup.elements[supervisor].value)-parseInt(tempobj.value);
                        message=message+"(+"+needs+")";
                        if (needs>0) document.markingSetup.elements[supervisorDisp].value="+"+needs;
                        else document.markingSetup.elements[supervisorDisp].value=needs;
                        if (needs>0) supervisorCountUnder+=needs;
                    }
                    supTCount+=parseInt(document.markingSetup.elements[supervisor].value);
                }
                
                
                
            }
            else if (cnt>0 && tempobj.name.substr(0,5)!="proj[") 
            {
                message=message+":"+parseFloat(tempobj.value);
                var tempobj2=document.markingSetup.elements[i-1];
                var sm="smT["+tempobj2.name+"]";
                var smDisp="smDisp["+tempobj2.name+"]";
                if (document.markingSetup.elements[sm]!=undefined) 
                {
                    if (parseInt(tempobj.value)>parseInt(document.markingSetup.elements[sm].value))
                    { 
                        var needs=parseInt(tempobj.value)-parseInt(document.markingSetup.elements[sm].value);
                        message=message+"(-"+needs+"!!)";
                        document.markingSetup.elements[smDisp].value="-"+needs+"!!";
                        smCountOver+=needs;
                        
                        returnVal=false;
                    }
                    if (parseInt(tempobj.value)<=parseInt(document.markingSetup.elements[sm].value))
                    {
                        var needs=parseInt(document.markingSetup.elements[sm].value)-parseInt(tempobj.value);
                        message=message+"(+"+needs+")";
                        if (needs>0) document.markingSetup.elements[smDisp].value="+"+needs;
                        else document.markingSetup.elements[smDisp].value=needs;
                        if (needs>0) smCountUnder+=needs;
                        
                    }
                    smTCount+=parseInt(document.markingSetup.elements[sm].value);
                }
                message=message+" ";
            }
            cnt++;
            
        }
            
        
        }
        var dispTotalOver="";
        var dispTotalUnder="";
        var dispSupTotalOver="";
        var dispSupTotalUnder=""      
        if (supervisorCountOver>0) dispSupTotalOver="(-"+supervisorCountOver+")"; else dispSupTotalOver="";
        if (supervisorCountUnder>0) dispSupTotalUnder="(+"+supervisorCountUnder+")"; else dispSupTotalUnder="";
        document.markingSetup.elements["supDispTotal"].value=dispSupTotalOver+" "+dispSupTotalUnder;
        if (smCountOver>0) dispTotalOver="(-"+smCountOver+")"; else dispTotalOver="";
        if (smCountUnder>0) dispTotalUnder="(+"+smCountUnder+")"; else dispTotalUnder="";
        document.markingSetup.elements["smDispTotal"].value=dispTotalOver+dispTotalUnder;
        document.markingSetup.elements["supTTotal"].value=supTCount+" (Sts:"+studentCount+")";
        document.markingSetup.elements["smTTotal"].value=smTCount+" (Sts:"+studentCount+")";
        message=message+"Total:"+supTCount+dispSupTotalOver+dispSupTotalUnder+":"+smTCount+dispTotalOver+dispTotalUnder;
        message=message+" Students:"+studentCount;
        if (document.markingSetup.elements["countSupSM"]!=undefined)  document.markingSetup.elements["countSupSM"].value=message;
        return false;       
    }
    
    function checkIfUpToDateList()
    {
        if (document.markingSetup.calculateTotals.checked==false) countSupervisorSecondMarker();    
    
    }
    
    
    
