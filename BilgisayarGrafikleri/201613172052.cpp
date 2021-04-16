#include <GL/glut.h>
//Pencere boyutunu belirledim
int en = 300;
int boy = 300;
//Köpek cismi için x y z koordinatlarýnýn baþlangýç noktalarý
float KopekX = 2.0f;
float KopekY = 0.6f;
float KopekZ = -9.f;
// Kedi cismi için x y z koordinatlarýnýn baþlangýç noktalarý
float KediX = -3.0f;
float KediY = 0.6f;
float KediZ = -9.0f;
//Dönmesi için açýlarýný tanýmlayalým
GLfloat aciPiramit = 0.0f;
GLfloat aciKup = 0.0f;
int cisimYenileme = 23; //cisimlerin dönme hýzý
//Köpek için tuþ basýldýðýnda çalýþacak yerlerin ve ne kadar ilerleyeceði kýsýmlar.
//Köpek için(Piramit) hareket tuþlarý; w(yukarý),s(aþaðý),a(sola),d(saða),z(ileri),x(geri).
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
void KopekGoturÝl(void)
{
    glLoadIdentity();
    KopekZ -= 0.1;
}
void KopekGoturGeri(void)
{
    glLoadIdentity();
    KopekZ += 0.1;
}
//Kedi için tuþ basýldýðýnda çalýþacak yerlerin ve ne kadar ilerleyeceði kýsýmlar.
//Kedi için(Küp) hareket tuþlarý; yön tuþlarý ileri geri saða sola için, page up(ileri), page down(geri).
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
void KediGoturÝl(void)
{
    glLoadIdentity();
    KediZ -= 0.1;
}
void KediGoturGeri(void)
{
    glLoadIdentity();
    KediZ += 0.1;
}
//Ayarlar kýsmý
void Ayarlar() {
    glClearColor(2.0, 5.0, 0.0, 0.0); //Pencerenin arka plan rengini belirtmek için kullanýlýr.
    glClearDepth(1.0f); //Derinlik tamponunun temizlenmesi saðlanýr.Arka plan derinliðini en uzaða ayarlanýr.
    glEnable(GL_DEPTH_TEST); //z ekseni için derinlik testi.
    glDepthFunc(GL_LEQUAL); //Karmaþýk grafikler için derinlik testi.
    glShadeModel(GL_SMOOTH); //Karmaþýk grafiklerde düzgün gölgelendirme yapmak için kullanýlýr.
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
//Klavyedeki tuþlarý belirleyip o tuþlara basýldýðýnda çalýþacak fonksiyonlarý tanýmladýk.
void klavye(int dugme, int x, int y)
{
    switch (dugme)
    {
    case GLUT_KEY_LEFT:KediGoturSol(); break;
    case GLUT_KEY_RIGHT:KediGoturSag(); break;
    case GLUT_KEY_UP:KediGoturYuk(); break;
    case GLUT_KEY_DOWN:KediGoturAs(); break;
    case GLUT_KEY_PAGE_UP:KediGoturÝl(); break;
    case GLUT_KEY_PAGE_DOWN:KediGoturGeri(); break;
    }
    glutPostRedisplay();//hareket(iþlem) sonrasý güncelleme için
}
void klavye(unsigned char dugme, int x, int y)
{//yalnýz karakter tuþlarýný kullanabiliriz
    switch (dugme)
    {
    case'w':KopekGoturYuk(); break;
    case's':KopekGoturAs(); break;
    case'a':KopekGoturSol(); break;
    case'd':KopekGoturSag(); break;
    case'z':KopekGoturÝl(); break;
    case'x':KopekGoturGeri(); break;
    
    }
    glutPostRedisplay();//hareket(iþlem) sonrasý güncelleme için
}

//Kediyi Çizdirelim. Küp Ýçin 6 tane yüz gerekli.
void cizimKedi() {

    glLoadIdentity(); 
    glTranslatef(KediX, KediY, KediZ); // þekli saða ve geriye kaydýr
    glRotatef(aciKup, 1.0f, 1.0f, 0.0f); // Rotate (1,0,0)-axis (x-ekseni etrafýnda dönüþ)

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
  
    glColor3f(1.0f, 1.0f, 0.0f); // Sarý
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    
    glColor3f(1.0f, 0.0f, 0.0f); // Kýrmýzý
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
   
    glColor3f(0.0f, 1.0f, 0.0f); // Yeþil
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd(); // Renkli küp çiziminin sonu.
   
}
//Köpek Çizdirelim. 4 tane üçgen lazým.
void cizimKopek() {
    glLoadIdentity(); 
    glTranslatef(KopekX, KopekY, KopekZ);
    glRotatef(aciPiramit, 1.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES); // piramit için 4 üçgen lazým
    //ön
    glColor3f(1.0f, 0.0f, 0.0f); // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // Yeþil
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);
    //sað
    glColor3f(1.0f, 0.0f, 0.0f); // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // yeþil
    glVertex3f(1.0f, -1.0f, -1.0f);
    // arka
    glColor3f(1.0f, 0.0f, 0.0f); // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // Yeþil
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Mavi
    glVertex3f(-1.0f, -1.0f, -1.0f);
    // sol
    glColor3f(1.0f, 0.0f, 0.0f); // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Mavi
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // Yeþil
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd(); // Piramit çizimi bitti.
  
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
//Zamanlayýcýmýzý oluþturalým.
void zamanlayici(int value) {
    glutPostRedisplay(); //CizimFonksiyonu()'nun yaptýðý iþlem sonrasý güncelleme için
    glutTimerFunc(cisimYenileme, zamanlayici, 0); // next timer call milliseconds later
}
//Pencerenin nasýl görüneceðini belirlemek için Görünüm Ayarlarýný yapmamýz lazým
void GorunumAyari(GLsizei x, GLsizei y) //x:geniþlik, y:yükseklik
{ // "GLsizei"(negatif olmayan tamsayý demektir. int width; diyebilirdik)
 // Yeni pencerenin en boy oranýný hesaplama
    if (y == 0) y = 1; // 0'a bölümden korunmak için
    GLfloat oran = (GLfloat)x / (GLfloat)y; //float oran; diyebilirdik
    /* Genellikle pencere geniþliði ile aynýdýr. Eðer viewport geniþlik / yükseklik oraný
    projeksiyondakinden farklý ise nesneler olduklarýndan farklý biçimde görünebilirler*/
    glViewport(0, 0, x, y);
    // en boy oranýný görünüm penceresiyle eþleþecek þekilde ayarlama:
    glMatrixMode(GL_PROJECTION); // projeksiyon (izdüþüm) matrisi
    //izdüþüm görünümüne ayarlamak için
    glLoadIdentity(); // Orjinal Duruma dönülür (Reset)
    // Perspectif projeksiyon yapar--> gluPerspective (theta, aspect, dnear, dfar)
    gluPerspective(45.0f, oran, 1.0f, 20.0f);
}
    int main(int argc, char** argv) {

        glutInit(&argc, argv); // GLUT'u baþlat
        glutInitDisplayMode(GLUT_DOUBLE); // çift tampon kullanma

        glutInitWindowPosition(50, 50); //pencere baþlangýç noktasý
        glutInitWindowSize(800, 600); // Pencere geniþlik ve yükseklik ayarlayalým
        glutCreateWindow("201613172052"); //pencere baþlýðý

        glutDisplayFunc(CizimFonksiyonu); // kendisine parametre olarak gönderilen CizimFonksiyon fonksiyonu çaðýrýr ve çizimi yapar
        glutKeyboardFunc(klavye);
        glutSpecialFunc(klavye);

            glutReshapeFunc(GorunumAyari); // Eðer pencere yeniden boyutlandýrýlýrsa yeni geniþlik ve yükseklik deðerleri atanýr.

            Ayarlar(); // Kendi OpenGL Ayarlarýmýz
        glutTimerFunc(0, zamanlayici, 0); 
        glutMainLoop(); // çizimi döngüye sokar.
        return 0;
    }