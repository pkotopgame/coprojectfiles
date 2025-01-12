﻿#ifndef _MPMAP_H_
#define _MPMAP_H_
#include "ZRBlock.h"
#include "MPTile.h"





#define UNDERWATER_HEIGHT		 -2.0f
#define UNDERWATER_TEXNO			22
#define MAX_OTHER_DATA              40
#define SKYDOOM_TEXTURE_MOVESPEED   10  
#define PI                          3.1415926535897932384626433832795f 

struct MPActiveMapSection
{
	MPTile* pTileData;							// Ö¸ÏòÊµ¼ÊµÄTileÊý¾Ý
	int			nX;									// MapSectionËùÔÚµÄÎ»ÖÃ
	int			nY;
	DWORD		dwActiveTime;						// ×îºóÒ»´ÎÊ¹ÓÃµÄÊ±¼ä
	DWORD		dwDataOffset;						// ÎÄ¼þÊý¾ÝÖ¸ÕëÎ»ÖÃ = 0, ±íÊ¾Ã»ÓÐÊý¾Ý

	void	Init()
	{
		pTileData = NULL;
		nX = 0;
		nY = 0;
		dwActiveTime = 0;
		dwDataOffset = 0;
	}
};
class  MPMap;
typedef long (CALLBACK* MAP_PROC)(int nFlag, int nSectionX,
	int nSectionY, unsigned long dwParam, MPMap* pthis);

class ZRBlock;

class MINDPOWER_API MPMap
{
public:

	MPMap();
	~MPMap();

	BOOL		Load(const char* pszMapName, BOOL bEdit = FALSE);
	// void		Create(int nWidth, int nHeight, const char *pszMapName, int nSectionWidth = 16, int nSectionHeight = 16);

	void		SetSectionTileData(int nX, int nY, BYTE btTexNo);
	void		SetMapProcFN(MAP_PROC pfn) { _pfnProc = pfn; }

	MPTile* GetTile(int nX, int nY);
	MPTile* GetGroupTile(int nX, int nY, int nGroupNo);
	void		DynamicLoading(DWORD dwTimeParam);
	void        FullLoading();
	void        ClearSectionArray();
	std::list<MPActiveMapSection*>* GetActiveSectionList() { return &_ActiveSectionList; }

	MPActiveMapSection* GetActiveSection(int nSectionX, int nSectionY);
	void                SetSectionBufferSize(int nSize) { _nSectionBufferSize = nSize; }
	void                ClearSectionData(int nSectionX, int nSectionY);
	MPActiveMapSection* LoadSectionData(int nSectionX, int nSectionY);

	void		FrameMove(DWORD dwTimeParam);
	void		Render();
	void		RenderSea();

	void		RenderSmMap();

	BOOL		GetPickPos(int nX, int nY, D3DXVECTOR3& vPickPos);
	BOOL        GetPickPosEditor(int nX, int nY, D3DXVECTOR3& vPickPos);

	int			GetWidth() { return _nWidth; }
	int			GetHeight() { return _nHeight; }
	int			GetSectionCntX() { return _nSectionCntX; }
	int			GetSectionCntY() { return _nSectionCntY; }
	int         GetSectionCnt() { return _nSectionCnt; }

	int			GetSectionWidth()
	{
		return _nSectionWidth;
	}
	int			GetSectionHeight()
	{
		return _nSectionHeight;
	}

	int         GetValidSectionCnt();

	void		SetShowSize(int nWidth, int nHeight)
	{
		if (nWidth != _nShowWidth || nHeight != _nShowHeight)
		{
			_nShowWidth = nWidth;
			_nShowHeight = nHeight;
			_nGridShowWidth = nWidth * 2;
			_nGridShowHeight = nHeight * 2;
		}
	}
	int			GetShowWidth() { return _nShowWidth; }
	int			GetShowHeight() { return _nShowHeight; }
	void		SetShowCenter(float fX, float fY)
	{
		_fShowCenterX = fX;
		_fShowCenterY = fY;
	}
	float		GetShowCenterX() { return _fShowCenterX; }
	float		GetShowCenterY() { return _fShowCenterY; }
	BOOL		IsPointVisible(float fX, float fY);

	void		SetSeaVisible(BOOL bSeaVisible) { _bSeaVisible = bSeaVisible; }
	BOOL		IsSeaVisible() { return _bSeaVisible; }
	float		GetHeight(float fX, float fY);
	void		ShowCenterPoint(BOOL bShow) { _bShowCenterPoint = bShow; }
	void        ClearAllSection(BOOL bSave);

	void		EnableVB(BOOL bUseVB) { _bUseVB = bUseVB; }
	void		EnableClip(BOOL bClip) { _bClip = bClip; }
	void		EnableNormalLight(BOOL bEnable) { _bEnableNormalLight = bEnable; }
	BOOL		IsEnableVB() { return _bUseVB; }
	BOOL		IsEnableClip() { return _bClip; }
	BOOL		IsEnableNormalLight() { return _bEnableNormalLight; }
	void		EnableWireFrame(BOOL bEnable) { _bWireFrame = bEnable; }
	BOOL        CanEdit() { return _bEdit; }
	void        EnableBatchRender(BOOL bEnable) { _bBatchRender = bEnable; }
	BOOL        IsBatchRender() { return _bBatchRender; }
	void        SetSeaDefaultColor(DWORD dwColor) { _dwSeaDefaultColor = dwColor; }
	void        UpdateRender(BOOL bReset = FALSE)
	{
		if (bReset) _nUpdateRender = 2; // ÐèÒªÖØÐÂÉú³ÉGroup (±ÈÈç¶ÁÅÌ, ÊÓÒ°±ä»¯)
		else       _nUpdateRender = 1; // Ö»ÐèÒªÖØÐÂ²úÉúVB(±ÈÈç±à¼­Æ÷, µÆ¹âÑÕÉ«¸üÐÂ)
	}

	float       GetGridHeight(int x, int y);    // x, y are small grid coordinates
	BYTE        IsGridBlock(int x, int y);      // x,yare small grid coordinates
	float		GetTileHeight(int x, int y);    // x,yÎª´ó¸ñ×ÓÃ××ø±ê
	short       GetTileRegionAttr(int x, int y);// x,yÎª´ó¸ñ×ÓÃ××ø±ê

public:

	DWORD       m_dwTerrainRenderTime;
	DWORD       m_dwSeaRenderTime;
	DWORD       m_dwLoadingTime[3]; // ×î½ü3´Î²»Îª0µÄ¶ÁÅÌÊ±¼ä
	DWORD       m_dwMaxLoadingTime;
	DWORD       m_dwActiveSectionCnt;
	DWORD       m_dwBatchTime;

public:
	bool		m_bCullTile;
protected:

	// MPMapSection*	_GetSection(int nSectionX, int nSectionY);
	void				_LoadSectionData(MPActiveMapSection* pSection);
	void				_SaveSection(MPActiveMapSection* pSection);
	void				_RenderSea(int nStartX, int nStartY);
	DWORD				_ReadSectionDataOffset(int nSectionX, int nSectionY);
	void				_WriteSectionDataOffset(int nSectionX, int nSectionY, DWORD dwDataOffset);
	void				_CalTileNormal(int nX, int nY);
	void				_RenderFocusRect();
	void                _GenerateTerrainGroup(int nTileStartX, int nTileStartY);
	BOOL                _AddRenderGroup(BYTE btLayer, int nTexNo, MPTile* pTile, short sTileX, short sTileY);
	void                _FillVB();
	void                _RenderVB(BOOL bWireframe = FALSE);


	// MPMapSection*			_pSectionData;

	MPTile* _pDefaultTile{ nullptr };
	MPTile* _RenderTileList[4096]{ nullptr };
	int _nRenderTileCnt{ 0 };
	int _nUpdateRender{ 2 };
	int _nLastTileStartX{ 0 };
	int _nLastTileStartY{ 0 };
	int _nLastGridStartX{ 0 };
	int _nLastGridStartY{ 0 };
	int _nGridShowWidth{ 0 };
	int _nGridShowHeight{ 0 };

	int _nLastSectionX{ 0 };
	int _nLastSectionY{ 0 };

	float _fHeightBuffer[200][200]{ 0 };
	BYTE _btBlockBuffer[200][200]{ 0 };
	float _fTileHeightBuffer[100][100]{ 0 };
	short _sTileRegionAttr[100][100]{ 0 };


#if(defined DRAW_SEA_USE_DYNAMIC_BUFFER)
	MPSeaTileVertex* _pVertBuf{ nullptr };
#else
	IDirect3DVertexBufferX* _pVB{ nullptr };
#endif

	IDirect3DVertexBufferX* _pLandVB{ nullptr };
	DWORD                       _dwLandVBSize{ 0 };


	int _nWidth{ 0 };
	int _nHeight{ 0 };
	int _nSectionWidth{ 0 }; // 每一块Section的宽度和高度
	int _nSectionHeight{ 0 };
	int _nSectionCntX{ 0 }; // 地图水平方向上Section的块数
	int _nSectionCntY{ 0 }; // 地图垂直方向上Section的块数
	int _nSectionCnt{ 0 }; // 地图上Section的总块数

	float _fShowCenterX{ 0 }; // 动态读入的中心位置
	float _fShowCenterY{ 0 };

	int _nShowWidth{ 0 }; // 可视范围
	int _nShowHeight{ 0 };

	BOOL _bRenderSea{ FALSE };

	std::list<MPActiveMapSection*>	_ActiveSectionList;
	MPActiveMapSection* _ActiveSectionArray[512][512]{ nullptr };
	int							    _nSectionStartX{ 0 };
	int							    _nSectionStartY{ 0 };
	DWORD* _pOffsetIdx{ nullptr };

	MAP_PROC					_pfnProc{ nullptr };			// µØÍ¼¶¯Ì¬¶ÁÈë»Øµ÷Í¨Öªº¯Êý

	FILE* _fp{ nullptr };				// µØÍ¼ÎÄ¼þ¾ä±ú
	BOOL						_bEdit{ TRUE };		// ÊÇ·ñ¿É±à¼­
	BOOL						_bSeaVisible{ TRUE };
	BOOL						_bShowCenterPoint{ FALSE };	// ÊÇ·ñÏÔÊ¾½¹µãºÍ½¹µãËùÔÚSection

	int _nWaterLoopFrame{ 0 };
	BOOL _bUseVB{ FALSE };
	BOOL _bUseLandVB{ TRUE };
	BOOL _bClip{ TRUE };
	BOOL _bWireFrame{ FALSE };
	int _nSectionBufferSize;
	BOOL _bBatchRender{ TRUE };
	BOOL _bEnableNormalLight{ FALSE };
	DWORD _dwLoadingCnt{ 0 };

	DWORD _dwSeaDefaultColor{ D3DCOLOR_ARGB(0xcf, 140, 140, 220) };

	LPBYTE m_pMapData{ nullptr };
	DWORD m_dwMapDataSize{ 0 };
	DWORD m_dwMapPos{ 0 };
	//jze
public:
	void        CreateSkyDoom(D3DXVECTOR3 center, float radius, char* txPath, bool hemisphere = true); //add by jze 2008.6.27
	void		SetupPixelFog(DWORD Color, DWORD Mode, float Start, float End, float Density); //add by jze 2008.7.3
	void        CloseFog() { g_Render.GetDevice()->SetRenderState(D3DRS_FOGENABLE, FALSE); }
	BOOL        IsSkyDoom() { return m_bSkyDoom; }
	void        SetSkyDoom(bool bSkyDoom) { m_bSkyDoom = bSkyDoom; }

	void		SetPathFindingRange(int val) { m_iRange = val; }
	ZRBlock* GetBlock() { return m_pBlock; }
	int			GetPathFindingRange() { return m_iRange; }
private:
	BOOL        UseShader();

private:
	DWORD       m_SkyDoomVertexShaderHandle;
	DWORD       m_SkyDoomPixelShaderHandle;

	BOOL						m_bSkyDoom{ FALSE };
	float                       m_txMoveSpeed{ 0 };

	MPSkyDoomVertex* m_pSkyDoomVB{ nullptr };

	ZRBlock* m_pBlock;
	int							m_iRange{ 512 };
};

inline MPTile* MPMap::GetTile(int nX, int nY)
{
	if (nX >= _nWidth || nY >= _nHeight || nX < 0 || nY < 0)
	{
		return _pDefaultTile;
	}

	int nSectionX = nX / _nSectionWidth;
	int nSectionY = nY / _nSectionHeight;

	MPActiveMapSection* pSection = GetActiveSection(nSectionX, nSectionY);
	if (pSection && pSection->pTileData)
	{
		int nOffX = nX % _nSectionWidth;
		int nOffY = nY % _nSectionHeight;
		return pSection->pTileData + nOffY * _nSectionWidth + nOffX;
	}

	return _pDefaultTile;
}


inline MPTile* MPMap::GetGroupTile(int nX, int nY, int nGroupNo)
{
	return GetTile(nX + MPTile::Offset[nGroupNo][0], nY + MPTile::Offset[nGroupNo][1]);
}

inline MPActiveMapSection* MPMap::GetActiveSection(int nSectionX, int nSectionY)
{
	return _ActiveSectionArray[nSectionY][nSectionX];
}

inline BOOL MPMap::IsPointVisible(float fX, float fY)
{
	float fStartX = _fShowCenterX - (float)_nShowWidth / 2;
	float fStartY = _fShowCenterY - (float)_nShowHeight / 2;

	float fEndX = fStartX + (float)_nShowWidth;
	float fEndY = fStartY + (float)_nShowHeight;

	// fStartX-=3;
	// fStartY-=3;
	// fEndX+=3;
	// fEndY+=3;
	if (fX >= fStartX && fY >= fStartY && fX <= fEndX && fY <= fEndY) return TRUE;
	return FALSE;
}

inline void CopyMapSection(MPActiveMapSection* pSource, MPActiveMapSection* pDest)
{
	memcpy(pDest, pSource, sizeof(MPActiveMapSection));
	memcpy(pDest->pTileData, pSource->pTileData, sizeof(MPTile) * 64);
}

inline float MPMap::GetTileHeight(int x, int y) // ´ó¸ñ×Ó×ø±ê
{
	int offx = x - _nLastTileStartX;
	int offy = y - _nLastTileStartY;

	if (offx < 0 || offx >= 100) return 0.0f;
	if (offy < 0 || offy >= 100) return 0.0f;

	return _fTileHeightBuffer[offy][offx];
}

inline short MPMap::GetTileRegionAttr(int x, int y) // ´ó¸ñ×Ó×ø±ê
{
	int offx = x - _nLastTileStartX;
	int offy = y - _nLastTileStartY;

	if (offx < 0 || offx >= 100) return 0;
	if (offy < 0 || offy >= 100) return 0;

	return _sTileRegionAttr[offy][offx];
}

inline float MPMap::GetGridHeight(int x, int y) // Small grid coordinates
{
	try
	{
		int offx = x - _nLastGridStartX;
		int offy = y - _nLastGridStartY;

		if (offx < 0 || offx >= _nGridShowWidth) return 0.0f;
		if (offy < 0 || offy >= _nGridShowHeight) return 0.0f;

		return _fHeightBuffer[offy][offx];
	}
	catch (...)
	{
		return 0.0f;
	}
}

inline BYTE MPMap::IsGridBlock(int x, int y) // Ð¡¸ñ×Ó×ø±ê
{
	int offx = x - _nLastGridStartX;
	int offy = y - _nLastGridStartY;

	if (offx < 0 || offx >= _nGridShowWidth)  return 1;
	if (offy < 0 || offy >= _nGridShowHeight) return 1;

	return _btBlockBuffer[offy][offx];
}

#endif