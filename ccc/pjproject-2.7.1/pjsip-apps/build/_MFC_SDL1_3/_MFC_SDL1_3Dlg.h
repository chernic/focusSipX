
// _MFC_SDL1_3Dlg.h : ͷ�ļ�
//

#pragma once


// C_MFC_SDL1_3Dlg �Ի���
class C_MFC_SDL1_3Dlg : public CDialog
{
// ����
public:
	C_MFC_SDL1_3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD__MFC_SDL1_3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
