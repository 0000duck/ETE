// : interface for the Workspace class.
/*_____________________________________________________
 |
 |	Intra3D Layer1 :  ��ͼ�ζ��� �� PointCloud
 |                                          
 |  �ļ���Workspace.h
 |
 |  ���ܣ��ڴ����
 |
 |  ������������ ��2002/10/10
 |
 |	Դ������ԣ�������Ӧ�ò���
 |_____________________________________________________*/

/*_____________________________________________________
 |  
 |	���� OpenGL �Ľ���ʽ��άͼ�������������
 |
 |	**   HustSurf for Windows 9X/NT  **
 |
 |	          ����Ȩ�ˣ������� 
 |	
 |	���пƼ���ѧ��еѧԺ (430074)
 |_____________________________________________________*/
#if !defined(WORKSPACE_H)
#define WORKSPACE_H

#include<stdio.h>

class  Workspace  
{
public:
	int KeepFile( FILE* pFile );
	FILE* OpenFile( const char*, const char*);
	Workspace();
	virtual ~Workspace();

  // The GetMemory...() functions use rhmalloc() to get memory.
  void*        GetMemory( int );
  int*         GetIntMemory( int );
  double*      GetDoubleMemory( int );

  // The GrowMemory...() functions use onrealloc() to get more memory
  // The pointer passed to GrowMemory() must be one that was returned
  // by any of the GetMemory...() calls.
  void*        GrowMemory( void*, int );
  int*         GrowIntMemory( int*, int );
  double*      GrowDoubleMemory( double*, int );

  // Calling the KeepMemory() function with a pointer returned from
  // one of the Get...() or Grow...() calls keeps the workspace destructor
  // from rhfree()ing the memory.  The caller is responsible for calling 
  // rhfree() to release the memory.
  bool KeepMemory( void* );  // returns TRUE for success and FALSE for failure


private:
  struct FBLK 
  {
    struct FBLK* pNext;
    FILE* pFile;
  } * m_pFileBlk;

  struct MBLK 
  {
    struct MBLK* pNext;
    void* pMem;
  } * m_pMemBlk;

private:
  // no implementation of the following
  Workspace( const Workspace& );            // no copy constructor
  Workspace& operator=( const Workspace& ); // no operator=
};

#endif // !defined(WORKSPACE_H)
