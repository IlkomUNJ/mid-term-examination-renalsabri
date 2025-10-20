1. For the first and second question i just simply thought of using boolean declared by ifEmpty to detect if there's object in the canvas, thus im using 3x3 because it's not to big nor small compared to checking every pixel (1x1) to detect, thus im using bool to detect which part of the segment is filled by object (1 and 0) here's the part of the code i implemented by using AI as my reference
 bool isEmpty = true;
            for(int m=-1;m<=1;m++){
                for(int n=-1;n<=1;n++){
                    QRgb rgbValue = image.pixel(i+m, j+n);
                    local_window[m+1][n+1] = (rgbValue != 0xffffffff);
                    if (local_window[m+1][n+1]){
                        isEmpty = false;
                    }
                }
            }
            if (!isEmpty) {
                cout << "Object at (" << i << ", " << j << ")" << endl;
                for (int m = 0; m < 3; ++m) {
                    for (int n = 0; n < 3; ++n) {
                        cout << (local_window[m][n] ? "1" : "0") << " ";
                    }
                    cout << endl;
                }
                cout << "         " << endl;
            } 

it shows coordinate like 
Object at (386, 204)
1 1 1 
1 1 0 
0 0 0 
         
Object at (386, 205)
1 1 0 
1 0 0 
0 0 0 
         
Object at (386, 206)
1 0 0 
0 0 0 
0 0 0 
         
Object at (387, 197)
0 0 1 
0 0 0 
0 0 0 
         
Object at (387, 198)
0 1 1 
0 0 0 
0 0 0 
         
Object at (387, 199)
1 1 1 
0 0 0 
0 0 0 
         
Object at (387, 200)
1 1 1 
0 0 0 
0 0 0 
         
Object at (387, 201)
1 1 1 
0 0 0 
0 0 0 
         
Object at (387, 202)
1 1 1 
0 0 0 
0 0 0 
         
Object at (387, 203)
1 1 1 
0 0 0 
0 0 0 
         
Object at (387, 204)
1 1 0 
0 0 0 
0 0 0 
         
Object at (387, 205)
1 0 0 
0 0 0 
0 0 0 

etc while the lines still on the window
            
2. For the second objective (3rd) we were given a task where our algorithm run automatically when we moved our cursor through the window and detect if theres object in the segment where our algorithm is implemented by marking it with small purple rectangle 

untuk nomor ini sebagian besar saya mengikuti AI karena saya hanya memahami kalau kita diminta untuk menambahkan variable serta pola deteksi (3x3) yang kita buat di problem sebelumnya, namun prosesnya sepertinya tidak berjalan untuk code yang baru karena sebagian besar mengikuti AI 




