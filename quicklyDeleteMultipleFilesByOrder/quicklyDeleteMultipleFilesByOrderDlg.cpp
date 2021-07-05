
// quicklyDeleteMultipleFilesByOrderDlg.cpp : 实现文件
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


// CquicklyDeleteMultipleFilesByOrderDlg 对话框




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


// CquicklyDeleteMultipleFilesByOrderDlg 消息处理程序

BOOL CquicklyDeleteMultipleFilesByOrderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_NORMAL);
	// MoveWindow()
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CquicklyDeleteMultipleFilesByOrderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CquicklyDeleteMultipleFilesByOrderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonAddFiles()
{
	AfxBeginThread(MyThreadProc, 0);
	
}

//选择目录
void CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonSelectDir()
{
	
	char szPath[MAX_PATH];     //存放选择的目录路径 
    ZeroMemory(szPath, sizeof(szPath));   

    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName = szPath;   
    bi.lpszTitle = "请选择需要删除的目录：";   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //弹出选择目录对话框
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

    if(lp && SHGetPathFromIDList(lp, szPath))   
    {
        // str.Format("选择的目录为 %s",  szPath);
        // AfxMessageBox(str); 
		dirPath = szPath;
        UpdateData(false);
    }
}

// 创建文件
void CquicklyDeleteMultipleFilesByOrderDlg::CreateFile(int n)
{
    // //文件指针
    // FILE *fp;
    // //使用“读入”方式打开文件
    // fp = fopen(fileName, "w");
    // //关闭文件
    // fclose(fp);
	ofstream *file;
	file = new ofstream[n];
	string	*filename;
	string	sname, tname, str;
	cout << "请输入文件的前缀名:";
	// cin >> sname;

	sname = "D:/filesTest/A/test";
	cout << "请输入文件的扩展名:";
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


//删除文件1
void CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
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




//删除文件2
void CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonDelete2()
{
	// TODO: 在此添加控件通知处理程序代码
	if(dirPath == "")
		return;
	//删除子文件
	string deleteCommand = "del /f/s/q " + dirPath + " > nul";
	//删除目录及子文件
	string rmdirCommand = "rmdir /s/q " + dirPath;
	system(deleteCommand.data());
	system(rmdirCommand.data());
	
}

//删除文件3
void CquicklyDeleteMultipleFilesByOrderDlg::OnBnClickedButtonDelete3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(dirPath == "")
		return;
	CString strDir = dirPath;
	if (strDir.IsEmpty())
    {
        RemoveDirectory(strDir);
        return;
    }

    //首先删除文件及子文件夹
    CFileFind   ff;
    BOOL bFound = ff.FindFile(strDir + _T("\\*"), 0);
    while (bFound)
    {
        bFound = ff.FindNextFile();
        if (ff.GetFileName() == _T(".") || ff.GetFileName() == _T(".."))        continue;

        // //去掉文件(夹)只读等属性
        // SetFileAttributes(ff.GetFilePath(), FILE_ATTRIBUTE_NORMAL);
        if (ff.IsDirectory())
        {
            //递归删除子文件夹
            // DeleteDirectory(ff.GetFilePath());
            RemoveDirectory(ff.GetFilePath());
        }
        else
        {
            DeleteFile(ff.GetFilePath());   //删除文件
        }

    }

    ff.Close();

    //然后删除该文件夹
    RemoveDirectory(strDir);


	
	dirPath="";
	UpdateData(false);
}
