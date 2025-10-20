1. For the first question i just simply thought of using boolean declared by ifEmpty to detect if there's object in the canvas here's the part of the code i implemented by using AI as my reference
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
            } 