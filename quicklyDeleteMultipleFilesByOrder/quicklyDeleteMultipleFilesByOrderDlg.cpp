
// quicklyDeleteMultipleFilesByOrderDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "quicklyDeleteMultipleFilesByOrder.h"
#include "quicklyDeleteMultipleFilesByOrderDlg.h"


#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>

#include "afxdialogex.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CquicklyDeleteMultipleFilesByOrderDlg �Ի���




CquicklyDeleteMultipleFilesByOrderDlg::CquicklyDeleteMultipleFilesByOrderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CquicklyDeleteMultipleFilesByOrderDlg::IDD, pParent)
	, dirPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CquicklyDeleteMultipleFilesByOrderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PATH, dirPath);
}

BEGIN_MESSAGE_MAP(CquicklyDeleteMultipleFilesByOrderDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD_FILES, &CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonAddFiles)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_DIR, &CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonSelectDir)
	ON_BN_CLICKED(IDC_BUTTON_DELETE2, &CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonDelete2)
	ON_BN_CLICKED(IDC_BUTTON_DELETE3, &CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonDelete3)
END_MESSAGE_MAP()


// CquicklyDeleteMultipleFilesByOrderDlg ��Ϣ�������

BOOL CquicklyDeleteMultipleFilesByOrderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_NORMAL);
	// MoveWindow()
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CquicklyDeleteMultipleFilesByOrderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CquicklyDeleteMultipleFilesByOrderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonAddFiles()
{
	AfxBeginThread(MyThreadProc, 0);
	
}

//ѡ��Ŀ¼
void CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonSelectDir()
{
	
	char szPath[MAX_PATH];     //���ѡ���Ŀ¼·�� 
    ZeroMemory(szPath, sizeof(szPath));   

    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName = szPath;   
    bi.lpszTitle = "��ѡ����Ҫɾ����Ŀ¼��";   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //����ѡ��Ŀ¼�Ի���
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

    if(lp && SHGetPathFromIDList(lp, szPath))   
    {
        // str.Format("ѡ���Ŀ¼Ϊ %s",  szPath);
        // AfxMessageBox(str); 
		dirPath = szPath;
        UpdateData(false);
    }
}

// �����ļ�
void CquicklyDeleteMultipleFilesByOrderDlg::CreateFile(int n)
{
    // //�ļ�ָ��
    // FILE *fp;
    // //ʹ�á����롱��ʽ���ļ�
    // fp = fopen(fileName, "w");
    // //�ر��ļ�
    // fclose(fp);
	ofstream *file;
	file = new ofstream[n];
	string	*filename;
	string	sname, tname, str;
	cout << "�������ļ���ǰ׺��:";
	// cin >> sname;

	sname = "D:/filesTest/A/test";
	cout << "�������ļ�����չ��:";
	// cin >> tname;
	tname = ".txt";
	filename = new string[n];
	int	i;
	char	a[10];
	for ( i = 1; i <= n; i++ )
	{
		sprintf_s( a, "%d", i );
		str		= a;
		filename[i - 1] = sname + str + tname;
	}
	for ( i = 1; i <= n; i++ )
	{
		file[i - 1].open( filename[i - 1], ios::out );
		WriteFile( file[i - 1] );
	}
}
void CquicklyDeleteMultipleFilesByOrderDlg::WriteFile( ofstream &file )
{
	int	LineNum, LineLength;
	int	i, j;
	LineNum = 1 + rand() % 50;
	for ( i = 1; i <= LineNum; i++ )
	{
		LineLength = 1 + rand() % 20;
		for ( j = 1; j <= LineLength; j++ )
		{
			file << rand() % 1000 << " ";
		}
		file << endl;
	}
	file.close();
}
UINT CquicklyDeleteMultipleFilesByOrderDlg::MyThreadProc(LPVOID Param) 
{
	// CString path = "D:/filesTest/";
	// char *str="D:/filesTest/A/12345";
	// for(char i = 'A';i <='D';i++)
	// {
	// 	CString pathFile;
	// 	pathFile = path + i;
	// 	if (!PathIsDirectory(pathFile))
	// 	{
	// 	::CreateDirectory(pathFile, 0);
	// 	}
	// 	
	// 	pathFile = pathFile+'/';
	//
	// 	for(int j = '0'; j <= '0' ;j++)
	// 	{
	// 			str = (char*)(LPCTSTR)(pathFile) ;
	// 			str = strcat(str,"ar");
	// 			CreateFile(str);
	// 	}
	// }
	CreateFile(9999);
	return TRUE;
}


//ɾ���ļ�1
void CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// CreateProcess();
	
	if(dirPath == "")
		return;
	string folderName = dirPath;
	// string deleteCommand = "del /f/s/q " + folderName + " > nul";
	string rmdirCommand = "rmdir /s/q " + folderName;
	// system(deleteCommand.data());
	system(rmdirCommand.data());
	// FILE rmdirFile;
	// ShellExecute(NULL,"rmdir /s/q",rmdirCommand,NULL, NULL, SW_SHOWNORMAL);
	dirPath="";
	UpdateData(false);
}




//ɾ���ļ�2
void CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonDelete2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(dirPath == "")
		return;
	//ɾ�����ļ�
	string deleteCommand = "del /f/s/q " + dirPath + " > nul";
	//ɾ��Ŀ¼�����ļ�
	string rmdirCommand = "rmdir /s/q " + dirPath;
	system(deleteCommand.data());
	system(rmdirCommand.data());
	
}

//ɾ���ļ�3
void CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonDelete3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(dirPath == "")
		return;
	CString strDir = dirPath;
	if (strDir.IsEmpty())
    {
        RemoveDirectory(strDir);
        return;
    }

    //����ɾ���ļ������ļ���
    CFileFind   ff;
    BOOL bFound = ff.FindFile(strDir + _T("\\*"), 0);
    while (bFound)
    {
        bFound = ff.FindNextFile();
        if (ff.GetFileName() == _T(".") || ff.GetFileName() == _T(".."))        continue;

        // //ȥ���ļ�(��)ֻ��������
        // SetFileAttributes(ff.GetFilePath(), FILE_ATTRIBUTE_NORMAL);
        if (ff.IsDirectory())
        {
            //�ݹ�ɾ�����ļ���
            // DeleteDirectory(ff.GetFilePath());
            RemoveDirectory(ff.GetFilePath());
        }
        else
        {
            DeleteFile(ff.GetFilePath());   //ɾ���ļ�
        }

    }

    ff.Close();

    //Ȼ��ɾ�����ļ���
    RemoveDirectory(strDir);


	
	dirPath="";
	UpdateData(false);
}
