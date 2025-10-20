1. For the first question i just simply thought of using boolean declared by ifEmpty to detect if there's object in the canvas, thus im using 3x3 because it's not to big nor small compared to checking every pixel (1x1) to detect, thus im using bool to detect which part of the segment is filled by object (1 and 0) here's the part of the code i implemented by using AI as my reference
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
            
2. For the second objective