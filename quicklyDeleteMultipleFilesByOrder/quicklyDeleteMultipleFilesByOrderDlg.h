
// quicklyDeleteMultipleFilesByOrderDlg.h : 头文件
//

#pragma once
#include <fstream>


// CquicklyDeleteMultipleFilesByOrderDlg 对话框
class CquicklyDeleteMultipleFilesByOrderDlg : public CDialogEx
{
// 构造
public:
	CquicklyDeleteMultipleFilesByOrderDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_QUICKLYDELETEMULTIPLEFILESBYORDER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAddFiles();

	static void CreateFile(int n);
	static void WriteFile(std::ofstream &file );
	static UINT MyThreadProc(LPVOID Param);
	afx_msg void OnBnClickedButtonDelete();
	// 需要删除的目录
	CString dirPath;
	afx_msg void OnBnClickedButtonSelectDir();
	afx_msg void OnBnClickedButtonDelete2();
	afx_msg void OnBnClickedButtonDelete3();
};
