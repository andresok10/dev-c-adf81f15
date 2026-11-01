#include <afxwin.h> // Biblioteca principal de MFC

// Clase de la aplicación principal
class CMyApp : public CWinApp
{
public:
    virtual BOOL InitInstance(); // Inicialización de la aplicación
};

// Clase de la ventana principal
class CMyDialog : public CDialog
{
public:
    CMyDialog() : CDialog(IDD_DIALOG1) {} // Constructor

protected:
    // Mapear eventos al sistema de mensajes
    afx_msg void OnButtonClicked(); // Función para manejar el clic del botón
    DECLARE_MESSAGE_MAP()
};

// Mapear mensajes a funciones
BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
    ON_BN_CLICKED(IDC_BUTTON1, &CMyDialog::OnButtonClicked) // Evento clic del botón
END_MESSAGE_MAP()

// Método que se ejecuta al iniciar la aplicación
BOOL CMyApp::InitInstance()
{
    CMyDialog myDialog; // Crear un objeto de la ventana principal
    m_pMainWnd = &myDialog; // Establecerla como la ventana principal
    myDialog.DoModal(); // Mostrar la ventana como cuadro de diálogo modal
    return FALSE; // Finalizar la aplicación después de cerrar el cuadro de diálogo
}

// Método que se ejecuta al hacer clic en el botón
void CMyDialog::OnButtonClicked()
{
    AfxMessageBox(_T("¡Hola, mundo desde MFC!")); // Mostrar un mensaje
}

// Crear un objeto de la aplicación principal
CMyApp theApp;