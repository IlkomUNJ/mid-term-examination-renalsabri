#include "drawingcanvas.h"


void DrawingCanvas::initializeIdealPatterns() {
    // Pola Garis Horizontal
    m_idealPatterns.push_back({{
        {{false, false, false}},
        {{true,  true,  true}},
        {{false, false, false}}
    }});
    // Pola Garis Vertikal
    m_idealPatterns.push_back({{
        {{false, true, false}},
        {{false, true, false}},
        {{false, true, false}}
    }});
    // Pola Garis Diagonal (kanan-bawah)
    m_idealPatterns.push_back({{
        {{true,  false, false}},
        {{false, true,  false}},
        {{false, false, true}}
    }});
    // Pola Garis Diagonal (kiri-bawah)
    m_idealPatterns.push_back({{
        {{false, false, true}},
        {{false, true,  false}},
        {{true,  false, false}}
    }});

}

DrawingCanvas::DrawingCanvas(QWidget *parent)  {
    // Set a minimum size for the canvas
    setMinimumSize(this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
    // Set a solid background color
    setStyleSheet("background-color: white; border: 1px solid gray;");
    initializeIdealPatterns();
}

void DrawingCanvas::clearPoints(){
    m_points.clear();
    // Trigger a repaint to clear the canvas
    m_detectedCandidates.clear();
    update();
}

void DrawingCanvas::paintLines(){
    /* Todo
     * Implement lines drawing per even pair
    */

    isPaintLinesClicked = true;
    update();
}

void DrawingCanvas::segmentDetection(){
    m_detectedCandidates.clear();
    QPixmap pixmap = this->grab(); //
    QImage image = pixmap.toImage();

    cout << "image width " << image.width() << endl;
    cout << "image height " << image.height() << endl;

    //To not crash we set initial size of the matrix


    // Get the pixel value as an ARGB integer (QRgb is a typedef for unsigned int)
    for(int i = 1; i < image.width()-1;i++){
        for(int j = 1; j < image.height()-1;j++){
            Array3x3 local_window;
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
                for (const auto& pattern : m_idealPatterns) {
                    if (local_window == pattern) {
                        // Jika cocok, simpan titik tengah (i, j) sebagai kandidat
                        m_detectedCandidates.push_back(QPoint(i, j));
                        break; // Pola ditemukan, lanjut ke piksel berikutnya
                    }
                }
            }
        }
    }
    update();

}

void DrawingCanvas::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set up the pen and brush for drawing the points
    QPen pen(Qt::blue, 5);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::blue));

    // Draw a small circle at each stored point
    for (const QPoint& point : std::as_const(m_points)) {
        painter.drawEllipse(point, 3, 3);
    }

    if(isPaintLinesClicked){
        cout << "paint lines block is called" << endl;
        pen.setColor(Qt::red);
        pen.setWidth(4); // 4-pixel wide line
        pen.setStyle(Qt::SolidLine);
        painter.setPen(pen);

        // Set the painter's pen to our custom pen.
        painter.setPen(pen);

        for(int i=0;i<m_points.size()-1;i+=2){
            //cout << m_points[i].x() << endl;
            painter.drawLine(m_points[i], m_points[i+1]);
        }
        isPaintLinesClicked = false;

        //return painter pen to blue
        pen.setColor(Qt::blue);
        painter.setPen(pen);
    }
    pen.setColor(QColor(128, 0, 128));
    pen.setWidth(1); // Kotak tipis
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush); // Hanya outline kotak, tidak diisi

    for (const QPoint& center : std::as_const(m_detectedCandidates)) {
        // 'center' adalah (i, j). Kita gambar kotak 3x3 di sekitarnya.
        // QRect(topLeftX, topLeftY, width, height)
        painter.drawRect(center.x() - 1, center.y() - 1, 3, 3);
    }
}

void DrawingCanvas::mousePressEvent(QMouseEvent *event) {
    // Add the mouse click position to our vector of points
    m_points.append(event->pos());
    // Trigger a repaint
    update();
}


