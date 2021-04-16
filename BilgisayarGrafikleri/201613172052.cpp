#include <GL/glut.h>
//Pencere boyutunu belirledim
int en = 300;
int boy = 300;
//K�pek cismi i�in x y z koordinatlar�n�n ba�lang�� noktalar�
float KopekX = 2.0f;
float KopekY = 0.6f;
float KopekZ = -9.f;
// Kedi cismi i�in x y z koordinatlar�n�n ba�lang�� noktalar�
float KediX = -3.0f;
float KediY = 0.6f;
float KediZ = -9.0f;
//D�nmesi i�in a��lar�n� tan�mlayal�m
GLfloat aciPiramit = 0.0f;
GLfloat aciKup = 0.0f;
int cisimYenileme = 23; //cisimlerin d�nme h�z�
//K�pek i�in tu� bas�ld���nda �al��acak yerlerin ve ne kadar ilerleyece�i k�s�mlar.
//K�pek i�in(Piramit) hareket tu�lar�; w(yukar�),s(a�a��),a(sola),d(sa�a),z(ileri),x(geri).
void KopekGoturSag(void)
{
    glLoadIdentity();//Koordinat sistemimiz etkilenmesin diye
    KopekX += 0.1;
}
void KopekGoturSol(void)
{
    glLoadIdentity();
    KopekX -= 0.1;
}
void KopekGoturYuk(void)
{
    glLoadIdentity();
    KopekY += 0.1;
}
void KopekGoturAs(void)
{
    glLoadIdentity();
    KopekY -= 0.1;
}
void KopekGotur�l(void)
{
    glLoadIdentity();
    KopekZ -= 0.1;
}
void KopekGoturGeri(void)
{
    glLoadIdentity();
    KopekZ += 0.1;
}
//Kedi i�in tu� bas�ld���nda �al��acak yerlerin ve ne kadar ilerleyece�i k�s�mlar.
//Kedi i�in(K�p) hareket tu�lar�; y�n tu�lar� ileri geri sa�a sola i�in, page up(ileri), page down(geri).
void KediGoturSag(void)
{
    glLoadIdentity();//Koordinat sistemimiz etkilenmesin diye
    KediX += 0.1;
}
void KediGoturSol(void)
{
    glLoadIdentity();
    KediX -= 0.1;
}
void KediGoturYuk(void)
{
    glLoadIdentity();
    KediY += 0.1;
}
void KediGoturAs(void)
{
    glLoadIdentity();
    KediY -= 0.1;
}
void KediGotur�l(void)
{
    glLoadIdentity();
    KediZ -= 0.1;
}
void KediGoturGeri(void)
{
    glLoadIdentity();
    KediZ += 0.1;
}
//Ayarlar k�sm�
void Ayarlar() {
    glClearColor(2.0, 5.0, 0.0, 0.0); //Pencerenin arka plan rengini belirtmek i�in kullan�l�r.
    glClearDepth(1.0f); //Derinlik tamponunun temizlenmesi sa�lan�r.Arka plan derinli�ini en uza�a ayarlan�r.
    glEnable(GL_DEPTH_TEST); //z ekseni i�in derinlik testi.
    glDepthFunc(GL_LEQUAL); //Karma��k grafikler i�in derinlik testi.
    glShadeModel(GL_SMOOTH); //Karma��k grafiklerde d�zg�n g�lgelendirme yapmak i�in kullan�l�r.
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
//Klavyedeki tu�lar� belirleyip o tu�lara bas�ld���nda �al��acak fonksiyonlar� tan�mlad�k.
void klavye(int dugme, int x, int y)
{
    switch (dugme)
    {
    case GLUT_KEY_LEFT:KediGoturSol(); break;
    case GLUT_KEY_RIGHT:KediGoturSag(); break;
    case GLUT_KEY_UP:KediGoturYuk(); break;
    case GLUT_KEY_DOWN:KediGoturAs(); break;
    case GLUT_KEY_PAGE_UP:KediGotur�l(); break;
    case GLUT_KEY_PAGE_DOWN:KediGoturGeri(); break;
    }
    glutPostRedisplay();//hareket(i�lem) sonras� g�ncelleme i�in
}
void klavye(unsigned char dugme, int x, int y)
{//yaln�z karakter tu�lar�n� kullanabiliriz
    switch (dugme)
    {
    case'w':KopekGoturYuk(); break;
    case's':KopekGoturAs(); break;
    case'a':KopekGoturSol(); break;
    case'd':KopekGoturSag(); break;
    case'z':KopekGotur�l(); break;
    case'x':KopekGoturGeri(); break;
    
    }
    glutPostRedisplay();//hareket(i�lem) sonras� g�ncelleme i�in
}

//Kediyi �izdirelim. K�p ��in 6 tane y�z gerekli.
void cizimKedi() {

    glLoadIdentity(); 
    glTranslatef(KediX, KediY, KediZ); // �ekli sa�a ve geriye kayd�r
    glRotatef(aciKup, 1.0f, 1.0f, 0.0f); // Rotate (1,0,0)-axis (x-ekseni etraf�nda d�n��)

    glBegin(GL_QUADS); 
    glColor3f(1.0f, 0.0f, 1.0f); // pembe
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    
    glColor3f(1.0f, 0.5f, 0.0f); // Turuncu
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    
    glColor3f(0.0f, 0.0f, 1.0f); // Mavi
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
  
    glColor3f(1.0f, 1.0f, 0.0f); // Sar�
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    
    glColor3f(1.0f, 0.0f, 0.0f); // K�rm�z�
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
   
    glColor3f(0.0f, 1.0f, 0.0f); // Ye�il
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd(); // Renkli k�p �iziminin sonu.
   
}
//K�pek �izdirelim. 4 tane ��gen laz�m.
void cizimKopek() {
    glLoadIdentity(); 
    glTranslatef(KopekX, KopekY, KopekZ);
    glRotatef(aciPiramit, 1.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES); // piramit i�in 4 ��gen laz�m
    //�n
    glColor3f(1.0f, 0.0f, 0.0f); // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // Ye�il
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);
    //sa�
    glColor3f(1.0f, 0.0f, 0.0f); // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // ye�il
    glVertex3f(1.0f, -1.0f, -1.0f);
    // arka
    glColor3f(1.0f, 0.0f, 0.0f); // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // Ye�il
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Mavi
    glVertex3f(-1.0f, -1.0f, -1.0f);
    // sol
    glColor3f(1.0f, 0.0f, 0.0f); // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Mavi
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // Ye�il
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd(); // Piramit �izimi bitti.
  
}
void CizimFonksiyonu() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    cizimKedi();
    glLoadIdentity();
    cizimKopek();
    glLoadIdentity();
    glutSwapBuffers();
    aciKup -= 0.2f;
    aciPiramit += 1.0f;

}
//Zamanlay�c�m�z� olu�tural�m.
void zamanlayici(int value) {
    glutPostRedisplay(); //CizimFonksiyonu()'nun yapt��� i�lem sonras� g�ncelleme i�in
    glutTimerFunc(cisimYenileme, zamanlayici, 0); // next timer call milliseconds later
}
//Pencerenin nas�l g�r�nece�ini belirlemek i�in G�r�n�m Ayarlar�n� yapmam�z laz�m
void GorunumAyari(GLsizei x, GLsizei y) //x:geni�lik, y:y�kseklik
{ // "GLsizei"(negatif olmayan tamsay� demektir. int width; diyebilirdik)
 // Yeni pencerenin en boy oran�n� hesaplama
    if (y == 0) y = 1; // 0'a b�l�mden korunmak i�in
    GLfloat oran = (GLfloat)x / (GLfloat)y; //float oran; diyebilirdik
    /* Genellikle pencere geni�li�i ile ayn�d�r. E�er viewport geni�lik / y�kseklik oran�
    projeksiyondakinden farkl� ise nesneler olduklar�ndan farkl� bi�imde g�r�nebilirler*/
    glViewport(0, 0, x, y);
    // en boy oran�n� g�r�n�m penceresiyle e�le�ecek �ekilde ayarlama:
    glMatrixMode(GL_PROJECTION); // projeksiyon (izd���m) matrisi
    //izd���m g�r�n�m�ne ayarlamak i�in
    glLoadIdentity(); // Orjinal Duruma d�n�l�r (Reset)
    // Perspectif projeksiyon yapar--> gluPerspective (theta, aspect, dnear, dfar)
    gluPerspective(45.0f, oran, 1.0f, 20.0f);
}
    int main(int argc, char** argv) {

        glutInit(&argc, argv); // GLUT'u ba�lat
        glutInitDisplayMode(GLUT_DOUBLE); // �ift tampon kullanma

        glutInitWindowPosition(50, 50); //pencere ba�lang�� noktas�
        glutInitWindowSize(800, 600); // Pencere geni�lik ve y�kseklik ayarlayal�m
        glutCreateWindow("201613172052"); //pencere ba�l���

        glutDisplayFunc(CizimFonksiyonu); // kendisine parametre olarak g�nderilen CizimFonksiyon fonksiyonu �a��r�r ve �izimi yapar
        glutKeyboardFunc(klavye);
        glutSpecialFunc(klavye);

            glutReshapeFunc(GorunumAyari); // E�er pencere yeniden boyutland�r�l�rsa yeni geni�lik ve y�kseklik de�erleri atan�r.

            Ayarlar(); // Kendi OpenGL Ayarlar�m�z
        glutTimerFunc(0, zamanlayici, 0); 
        glutMainLoop(); // �izimi d�ng�ye sokar.
        return 0;
    }