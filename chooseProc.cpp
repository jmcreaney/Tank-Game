#include<windows.h>

#include "game.h"
#include "tankData.h"
#include "chooseStruct.h"

using namespace std;

extern int plPoints1;
extern int plPoints2;
extern int year;
extern int month;


extern control * manage;

extern bool AI;

extern std::vector<tankData>data;

std::vector<chooseStruct> p1chosen;
std::vector<chooseStruct> p2chosen;
std::vector<chooseStruct> cs; 


BOOL    CALLBACK chooseProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
        

  int count; 
  int total;
  int temp;
  
      HWND avlTnks = GetDlgItem(hwnd, IDC_AVTNKLIST);
      HWND chsTnks = GetDlgItem(hwnd, IDC_CHTNKLIST);  
      HWND tnkPts  = GetDlgItem(hwnd, IDC_PNTSSLIST);

  switch(msg){
  	            
    case WM_INITDIALOG:{
    	
    	total = 0;
       if(cs.size()){cs.clear();}
       for(std::vector<tankData>::iterator itr = data.begin();
           itr != data.end(); itr++){    
				if(itr->gtCntry() == manage->gtCurrent()){			
					if(itr->gtYear() < year){
						    chooseStruct ch(itr->gtNameC(), count++, itr->gtPoints(),total);;
              				cs.push_back(ch);						
              		}	
              		if((itr->gtYear() == year) && (itr->gtMonth() <= month)){
              				chooseStruct ch(itr->gtNameC(), count++, itr->gtPoints(),total);;
              				cs.push_back(ch);   
              		}					
				}
			total++;	
		   }		
          
         
       char buffer[32];
       for(std::vector<chooseStruct>::iterator itr = cs.begin();
           itr != cs.end(); itr++){
               
           int pos = (int)SendMessage(avlTnks, LB_ADDSTRING, 0, 
               (LPARAM) itr->name); 
			     
           int pos2 = (int)SendMessage(tnkPts, LB_ADDSTRING, 0, 
               (LPARAM) itoa(itr->pts,buffer,10));  
       } 
	 

	break;             
    }
    
    case WM_PAINT:
    	
    	char str[3];   	
    	sprintf(str, "%d", plPoints1);

      PAINTSTRUCT ps; 
      HDC hdc;
      hdc = BeginPaint(hwnd, &ps);    	
      	TextOut(hdc,210,7,str,3);
      EndPaint(hwnd, &ps);	
      
    case WM_COMMAND:
    	
        switch(LOWORD(wp)){    
        
        case IDOK:
        if(manage->gtWhoCurent() == 1){
			 manage->swap(); 
		}
			 	 
          if(!p1chosen.empty()){
           	for(int l = 0; l != p1chosen.size(); l++){		
		  		makeTank(p1chosen[l].dataElement);	  		
			}
		  EndDialog(hwnd, IDOK);
		}

			  
        break;
        
        case IDC_AVTNKLIST:
           switch(HIWORD(wp)){
                              
              case LBN_SELCHANGE:{
                   HWND avlTnks = GetDlgItem(hwnd, IDC_AVTNKLIST);                  
                   int chItem = (int)SendMessage(avlTnks, LB_GETCURSEL,0,0);
                   int i = (int)SendMessage(avlTnks, LB_GETITEMDATA, chItem,0); 
                   int n = cs[chItem].place;  
                  
                   temp = plPoints1 - cs[chItem].pts;       
				   if(temp < 0){MessageBox(NULL, "Infsfficent Points!" , "Warning!" , MB_OK);}         
                   else{
				      plPoints1 = temp;                               
                      chooseStruct choice = cs[chItem];
                      p1chosen.push_back(choice); 
                      
                      const char * chName = cs[chItem].name;
                      
                     SendMessage(chsTnks, LB_ADDSTRING , 0, (LPARAM) chName);  
    	
      				 SendMessage(chsTnks, WM_SETREDRAW, TRUE, 0L);   
                     InvalidateRect(hwnd,NULL,TRUE);           
				   }	
				}
				       
              return true;                  
          }
             
        break;
        
        case IDC_CHTNKLIST:
           switch(HIWORD(wp)){
                            
              case LBN_SELCHANGE:{
              	   int i;
                   HWND chsTnks = GetDlgItem(hwnd, IDC_CHTNKLIST); 
                   int chItem = (int)SendMessage(chsTnks, LB_GETCURSEL,0,0); 
                   if(chItem > 1){				
                      i = 1+(int)SendMessage(chsTnks, LB_GETITEMDATA, chItem,0); 
                  }else {
                  		i = (int)SendMessage(chsTnks, LB_GETITEMDATA, chItem,0); 
				  }
                   		   
				   SendMessage(chsTnks, LB_DELETESTRING, i, 0); 
				 				   
				   plPoints1 = plPoints1 + p1chosen[chItem].pts; 
				   p1chosen.erase(p1chosen.begin()+chItem);
				       
				  InvalidateRect(hwnd,NULL,TRUE);          
              }
           break;         
           } 
        }
  }
  return FALSE;     
}                        

BOOL    CALLBACK chooseProc2(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
	
  cs.clear(); 
  int count; 
  int temp;
  int total;
  
      HWND avlTnks = GetDlgItem(hwnd, IDC_AVTNKLIST);
      HWND chsTnks = GetDlgItem(hwnd, IDC_CHTNKLIST);  
      HWND tnkPts  = GetDlgItem(hwnd, IDC_PNTSSLIST);
      

  switch(msg){
            
    case WM_INITDIALOG:{

		total = 0;
       if(cs.size()){cs.clear();}
       for(std::vector<tankData>::iterator itr = data.begin();
           itr != data.end(); itr++){    
				if(itr->gtCntry() == manage->gtCurrent()){			
					if(itr->gtYear() < year){
						    chooseStruct ch(itr->gtNameC(), count++, itr->gtPoints(),total);;
              				cs.push_back(ch);						
              		}	
              		if((itr->gtYear() == year) && (itr->gtMonth() <= month)){
              				chooseStruct ch(itr->gtNameC(), count++, itr->gtPoints(),total);
              				cs.push_back(ch);   
              		}			
				}
		total++;
		
        } 
		    
       char buffer[32];
       for(std::vector<chooseStruct>::iterator itr = cs.begin();
           itr != cs.end(); itr++){
               
           int pos = (int)SendMessage(avlTnks, LB_ADDSTRING, 0, 
               (LPARAM) itr->name); 
			     
           int pos2 = (int)SendMessage(tnkPts, LB_ADDSTRING, 0, 
               (LPARAM) itoa(itr->pts,buffer,10));  
       } 
	 

	break;             
    }

    case WM_PAINT:
    	
    	char str[3];   	
    	sprintf(str, "%d", plPoints2);

      PAINTSTRUCT ps; 
      HDC hdc;
      hdc = BeginPaint(hwnd, &ps);    	
      	TextOut(hdc,210,7,str,3);
      EndPaint(hwnd, &ps);	
   
    case WM_COMMAND:
    	
        switch(LOWORD(wp)){    
        case IDOK:
      
		 if(manage->gtWhoCurent() == 2){
			 manage->swap(); 
		}

		  
          if(!p2chosen.empty()){
           	for(int l = 0; l != p2chosen.size(); l++){		
		  		makeTank(p2chosen[l].dataElement);;	  		
			}
			EndDialog(hwnd, IDOK);
		}
	      
        break;

        case IDC_AVTNKLIST:
        	
           switch(HIWORD(wp)){
                              
              case LBN_SELCHANGE:{
            	
                   HWND avlTnks = GetDlgItem(hwnd, IDC_AVTNKLIST);                  
                   int chItem = (int)SendMessage(avlTnks, LB_GETCURSEL,0,0);
                   int i = (int)SendMessage(avlTnks, LB_GETITEMDATA, chItem,0); 
                   int n = cs[chItem].place;  
                  
                   temp = plPoints2 - cs[chItem].pts;       
				   if(temp < 0){MessageBox(NULL, "Infsfficent Points!" , "Warning!" , MB_OK);}         
                   else{
				      plPoints2 = temp;                               
                      chooseStruct choice = cs[chItem];
                      p2chosen.push_back(choice); 
                      
                      const char * chName = cs[chItem].name;
                      
                      SendMessage(chsTnks, LB_ADDSTRING , 0, (LPARAM) chName);  
    	
      				  SendMessage(chsTnks, WM_SETREDRAW, TRUE, 0L);   
                      InvalidateRect(hwnd,NULL,TRUE);  
					       
				   }	 
				}
				       
              return true;                  
          }
          
        break;
       
        case IDC_CHTNKLIST:
           switch(HIWORD(wp)){
                             
              case LBN_SELCHANGE:{
              	   int i;
                   HWND chsTnks = GetDlgItem(hwnd, IDC_CHTNKLIST); 
                   int chItem = (int)SendMessage(chsTnks, LB_GETCURSEL,0,0); 
                   if(chItem > 1){				
                      i = 1+(int)SendMessage(chsTnks, LB_GETITEMDATA, chItem,0); 
                  }else {
                  		i = (int)SendMessage(chsTnks, LB_GETITEMDATA, chItem,0); 
				  }
                   		   
				   SendMessage(chsTnks, LB_DELETESTRING, i, 0); 
				 				   
				   plPoints2 = plPoints2 + p2chosen[chItem].pts; 
				   p2chosen.erase(p2chosen.begin()+chItem);
				       
				  InvalidateRect(hwnd,NULL,TRUE);          				        
              } 
           break;          
           }  
        }  
  }
  return FALSE;   
            
}    

