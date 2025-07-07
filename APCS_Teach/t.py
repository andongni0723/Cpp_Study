# -*- coding: utf-8 -*-
RAW = """ 		 			   	       				 	  	      		  			 		  	 	 			 	   			  		  	 			  			 	   		 				 	 					 		 	  	    	 	     	 	  		 	  	 		  		   	      		 			   	       				 	  				 	  	       		   	    	 	   	       	       	       	      			      	       		   	    	 	  		  	 	 		 		   			  		 		 	  	 		  		   	      		 			   	       				    	       		 	      	 	   	       	       	       	      			     			  	  		 	  	 		 			  			 	    	       	   	  	  			  	  				  	      	 	  		 	  				 	  		   	 	 	 	 	 	 	   	  	  	 	  				 	  			   	   	     	 	  		  	 	 		 		   			  		 		  	 	    	 	   	       	       	       	      			     			  	  		 	  	 		 			  			 	    	       		  	     	 	   	       	       	       	      		  		  		 				 			  	   	      				     	      		 	  	 		 			   	       	 	     		 	    	 			   	 			  		 			   	 	  	  	 			  			  		 			 	   		  	 	 			      	 	     		  	   	 	  	    	 	   	       	       	       	       	       	       	       	      			     			  	  		 	  	 		 			  			 	    	       	   	   	       	   	     	 	   	       	       	       	       	       	       	       	      			     			  	  		 	  	 		 			  			 	    	      				       	 	   	       	       	       	      		  	 	 		 			  		  	      	 	   	       	       	       	      		  		  		 				 			  	   	      				     	      		 	  	 		 			   	       	 	     		   	  	 			   	 			  		 			   	 	  	  	 			  			  		 			 	   		  	 	 			      	 	     		  	   	 	  	    	 	   	       	       	       	       	       	       	       	      			     			  	  		 	  	 		 			  			 	    	       	   	   	       	   	     	 	   	       	       	       	       	       	       	       	      			     			  	  		 	  	 		 			  			 	    	      				       	 	   	       	       	       	      		  	 	 		 			  		  	      	 	  		  	 	 		 			  		  	      	 	 """

bits = []
for ch in RAW:
    if ch == " ":
        bits.append("0")
    elif ch == "\t":
        bits.append("1")
    # 忽略其他換行或不可見符號

bit_str = "".join(bits)
# 將 bit 串每 8 位切片並轉成對應字元
decoded_bytes = bytes(int(bit_str[i:i+8], 2) for i in range(0, len(bit_str), 8))
print(decoded_bytes.decode("utf-8", errors="replace"))
