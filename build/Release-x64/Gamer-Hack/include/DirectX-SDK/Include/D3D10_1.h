

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __d3d10_1_h__
#define __d3d10_1_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ID3D10BlendState1_FWD_DEFINED__
#define __ID3D10BlendState1_FWD_DEFINED__
typedef interface ID3D10BlendState1 ID3D10BlendState1;
#endif 	/* __ID3D10BlendState1_FWD_DEFINED__ */


#ifndef __ID3D10ShaderResourceView1_FWD_DEFINED__
#define __ID3D10ShaderResourceView1_FWD_DEFINED__
typedef interface ID3D10ShaderResourceView1 ID3D10ShaderResourceView1;
#endif 	/* __ID3D10ShaderResourceView1_FWD_DEFINED__ */


#ifndef __ID3D10Device1_FWD_DEFINED__
#define __ID3D10Device1_FWD_DEFINED__
typedef interface ID3D10Device1 ID3D10Device1;
#endif 	/* __ID3D10Device1_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_d3d10_1_0000_0000 */
/* [local] */ 

#if defined( __d3d10_h__ ) && !defined( D3D10_ARBITRARY_HEADER_ORDERING )
#error d3d10.h is included before d3d10_1.h, and it will confuse tools that honor SAL annotations. \
If possibly targeting d3d10.1, include d3d10_1.h instead of d3d10.h, or ensure d3d10_1.h is included before d3d10.h
#endif
#ifndef _D3D10_1_CONSTANTS
#define _D3D10_1_CONSTANTS
#define	D3D10_1_DEFAULT_SAMPLE_MASK	( 0xffffffff )

#define D3D10_1_FLOAT16_FUSED_TOLERANCE_IN_ULP	( 0.6 )
#define D3D10_1_FLOAT32_TO_INTEGER_TOLERANCE_IN_ULP	( 0.6f )
#define	D3D10_1_GS_INPUT_REGISTER_COUNT	( 32 )

#define	D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT	( 32 )

#define	D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENTS_COMPONENTS	( 128 )

#define	D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT	( 32 )

#define	D3D10_1_PS_OUTPUT_MASK_REGISTER_COMPONENTS	( 1 )

#define	D3D10_1_PS_OUTPUT_MASK_REGISTER_COMPONENT_BIT_COUNT	( 32 )

#define	D3D10_1_PS_OUTPUT_MASK_REGISTER_COUNT	( 1 )

#define	D3D10_1_SHADER_MAJOR_VERSION	( 4 )

#define	D3D10_1_SHADER_MINOR_VERSION	( 1 )

#define	D3D10_1_SO_BUFFER_MAX_STRIDE_IN_BYTES	( 2048 )

#define	D3D10_1_SO_BUFFER_MAX_WRITE_WINDOW_IN_BYTES	( 256 )

#define	D3D10_1_SO_BUFFER_SLOT_COUNT	( 4 )

#define	D3D10_1_SO_MULTIPLE_BUFFER_ELEMENTS_PER_BUFFER	( 1 )

#define	D3D10_1_SO_SINGLE_BUFFER_COMPONENT_LIMIT	( 64 )

#define	D3D10_1_STANDARD_VERTEX_ELEMENT_COUNT	( 32 )

#define	D3D10_1_SUBPIXEL_FRACTIONAL_BIT_COUNT	( 8 )

#define	D3D10_1_VS_INPUT_REGISTER_COUNT	( 32 )

#define	D3D10_1_VS_OUTPUT_REGISTER_COUNT	( 32 )

#endif
#include "d3d10.h" //

typedef 
enum D3D10_FEATURE_LEVEL1
    {	D3D10_FEATURE_LEVEL_10_0	= 0xa000,
	D3D10_FEATURE_LEVEL_10_1	= 0xa100,
	D3D10_FEATURE_LEVEL_9_1	= 0x9100,
	D3D10_FEATURE_LEVEL_9_2	= 0x9200,
	D3D10_FEATURE_LEVEL_9_3	= 0x9300
    } 	D3D10_FEATURE_LEVEL1;

typedef struct D3D10_RENDER_TARGET_BLEND_DESC1
    {
    BOOL BlendEnable;
    D3D10_BLEND SrcBlend;
    D3D10_BLEND DestBlend;
    D3D10_BLEND_OP BlendOp;
    D3D10_BLEND SrcBlendAlpha;
    D3D10_BLEND DestBlendAlpha;
    D3D10_BLEND_OP BlendOpAlpha;
    UINT8 RenderTargetWriteMask;
    } 	D3D10_RENDER_TARGET_BLEND_DESC1;

typedef struct D3D10_BLEND_DESC1
    {
    BOOL AlphaToCoverageEnable;
    BOOL IndependentBlendEnable;
    D3D10_RENDER_TARGET_BLEND_DESC1 RenderTarget[ 8 ];
    } 	D3D10_BLEND_DESC1;



extern RPC_IF_HANDLE __MIDL_itf_d3d10_1_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_d3d10_1_0000_0000_v0_0_s_ifspec;

#ifndef __ID3D10BlendState1_INTERFACE_DEFINED__
#define __ID3D10BlendState1_INTERFACE_DEFINED__

/* interface ID3D10BlendState1 */
/* [unique][local][object][uuid] */ 


EXTERN_C const IID IID_ID3D10BlendState1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EDAD8D99-8A35-4d6d-8566-2EA276CDE161")
    ID3D10BlendState1 : public ID3D10BlendState
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc1( 
            /* [annotation] */ 
            __out  D3D10_BLEND_DESC1 *pDesc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ID3D10BlendState1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ID3D10BlendState1 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ID3D10BlendState1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ID3D10BlendState1 * This);
        
        void ( STDMETHODCALLTYPE *GetDevice )( 
            ID3D10BlendState1 * This,
            /* [annotation] */ 
            __out  ID3D10Device **ppDevice);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            ID3D10BlendState1 * This,
            /* [annotation] */ 
            __in  REFGUID guid,
            /* [annotation] */ 
            __inout  UINT *pDataSize,
            /* [annotation] */ 
            __out_bcount_opt(*pDataSize)  void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            ID3D10BlendState1 * This,
            /* [annotation] */ 
            __in  REFGUID guid,
            /* [annotation] */ 
            __in  UINT DataSize,
            /* [annotation] */ 
            __in_bcount_opt(DataSize)  const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            ID3D10BlendState1 * This,
            /* [annotation] */ 
            __in  REFGUID guid,
            /* [annotation] */ 
            __in_opt  const IUnknown *pData);
        
        void ( STDMETHODCALLTYPE *GetDesc )( 
            ID3D10BlendState1 * This,
            /* [annotation] */ 
            __out  D3D10_BLEND_DESC *pDesc);
        
        void ( STDMETHODCALLTYPE *GetDesc1 )( 
            ID3D10BlendState1 * This,
            /* [annotation] */ 
            __out  D3D10_BLEND_DESC1 *pDesc);
        
        END_INTERFACE
    } ID3D10BlendState1Vtbl;

    interface ID3D10BlendState1
    {
        CONST_VTBL struct ID3D10BlendState1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ID3D10BlendState1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ID3D10BlendState1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ID3D10BlendState1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ID3D10BlendState1_GetDevice(This,ppDevice)	\
    ( (This)->lpVtbl -> GetDevice(This,ppDevice) ) 

#define ID3D10BlendState1_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,guid,pDataSize,pData) ) 

#define ID3D10BlendState1_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,guid,DataSize,pData) ) 

#define ID3D10BlendState1_SetPrivateDataInterface(This,guid,pData)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,guid,pData) ) 


#define ID3D10BlendState1_GetDesc(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc(This,pDesc) ) 


#define ID3D10BlendState1_GetDesc1(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc1(This,pDesc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ID3D10BlendState1_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_d3d10_1_0000_0001 */
/* [local] */ 

typedef struct D3D10_TEXCUBE_ARRAY_SRV1
    {
    UINT MostDetailedMip;
    UINT MipLevels;
    UINT First2DArrayFace;
    UINT NumCubes;
    } 	D3D10_TEXCUBE_ARRAY_SRV1;

typedef D3D_SRV_DIMENSION D3D10_SRV_DIMENSION1;

typedef struct D3D10_SHADER_RESOURCE_VIEW_DESC1
    {
    DXGI_FORMAT Format;
    D3D10_SRV_DIMENSION1 ViewDimension;
    union 
        {
        D3D10_BUFFER_SRV Buffer;
        D3D10_TEX1D_SRV Texture1D;
        D3D10_TEX1D_ARRAY_SRV Texture1DArray;
        D3D10_TEX2D_SRV Texture2D;
        D3D10_TEX2D_ARRAY_SRV Texture2DArray;
        D3D10_TEX2DMS_SRV Texture2DMS;
        D3D10_TEX2DMS_ARRAY_SRV Texture2DMSArray;
        D3D10_TEX3D_SRV Texture3D;
        D3D10_TEXCUBE_SRV TextureCube;
        D3D10_TEXCUBE_ARRAY_SRV1 TextureCubeArray;
        } 	;
    } 	D3D10_SHADER_RESOURCE_VIEW_DESC1;



extern RPC_IF_HANDLE __MIDL_itf_d3d10_1_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_d3d10_1_0000_0001_v0_0_s_ifspec;

#ifndef __ID3D10ShaderResourceView1_INTERFACE_DEFINED__
#define __ID3D10ShaderResourceView1_INTERFACE_DEFINED__

/* interface ID3D10ShaderResourceView1 */
/* [unique][local][object][uuid] */ 


EXTERN_C const IID IID_ID3D10ShaderResourceView1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B7E4C87-342C-4106-A19F-4F2704F689F0")
    ID3D10ShaderResourceView1 : public ID3D10ShaderResourceView
    {
    public:
        virtual void STDMETHODCALLTYPE GetDesc1( 
            /* [annotation] */ 
            __out  D3D10_SHADER_RESOURCE_VIEW_DESC1 *pDesc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ID3D10ShaderResourceView1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ID3D10ShaderResourceView1 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ID3D10ShaderResourceView1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ID3D10ShaderResourceView1 * This);
        
        void ( STDMETHODCALLTYPE *GetDevice )( 
            ID3D10ShaderResourceView1 * This,
            /* [annotation] */ 
            __out  ID3D10Device **ppDevice);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            ID3D10ShaderResourceView1 * This,
            /* [annotation] */ 
            __in  REFGUID guid,
            /* [annotation] */ 
            __inout  UINT *pDataSize,
            /* [annotation] */ 
            __out_bcount_opt(*pDataSize)  void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            ID3D10ShaderResourceView1 * This,
            /* [annotation] */ 
            __in  REFGUID guid,
            /* [annotation] */ 
            __in  UINT DataSize,
            /* [annotation] */ 
            __in_bcount_opt(DataSize)  const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            ID3D10ShaderResourceView1 * This,
            /* [annotation] */ 
            __in  REFGUID guid,
            /* [annotation] */ 
            __in_opt  const IUnknown *pData);
        
        void ( STDMETHODCALLTYPE *GetResource )( 
            ID3D10ShaderResourceView1 * This,
            /* [annotation] */ 
            __out  ID3D10Resource **ppResource);
        
        void ( STDMETHODCALLTYPE *GetDesc )( 
            ID3D10ShaderResourceView1 * This,
            /* [annotation] */ 
            __out  D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc);
        
        void ( STDMETHODCALLTYPE *GetDesc1 )( 
            ID3D10ShaderResourceView1 * This,
            /* [annotation] */ 
            __out  D3D10_SHADER_RESOURCE_VIEW_DESC1 *pDesc);
        
        END_INTERFACE
    } ID3D10ShaderResourceView1Vtbl;

    interface ID3D10ShaderResourceView1
    {
        CONST_VTBL struct ID3D10ShaderResourceView1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ID3D10ShaderResourceView1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ID3D10ShaderResourceView1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ID3D10ShaderResourceView1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ID3D10ShaderResourceView1_GetDevice(This,ppDevice)	\
    ( (This)->lpVtbl -> GetDevice(This,ppDevice) ) 

#define ID3D10ShaderResourceView1_GetPrivateData(This,guid,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,guid,pDataSize,pData) ) 

#define ID3D10ShaderResourceView1_SetPrivateData(This,guid,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,guid,DataSize,pData) ) 

#define ID3D10ShaderResourceView1_SetPrivateDataInterface(This,guid,pData)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,guid,pData) ) 


#define ID3D10ShaderResourceView1_GetResource(This,ppResource)	\
    ( (This)->lpVtbl -> GetResource(This,ppResource) ) 


#define ID3D10ShaderResourceView1_GetDesc(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc(This,pDesc) ) 


#define ID3D10ShaderResourceView1_GetDesc1(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc1(This,pDesc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ID3D10ShaderResourceView1_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_d3d10_1_0000_0002 */
/* [local] */ 

typedef 
enum D3D10_STANDARD_MULTISAMPLE_QUALITY_LEVELS
    {	D3D10_STANDARD_MULTISAMPLE_PATTERN	= 0xffffffff,
	D3D10_CENTER_MULTISAMPLE_PATTERN	= 0xfffffffe
    } 	D3D10_STANDARD_MULTISAMPLE_QUALITY_LEVELS;



extern RPC_IF_HANDLE __MIDL_itf_d3d10_1_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_d3d10_1_0000_0002_v0_0_s_ifspec;

#ifndef __ID3D10Device1_INTERFACE_DEFINED__
#define __ID3D10Device1_INTERFACE_DEFINED__

/* interface ID3D10Device1 */
/* [unique][local][object][uuid] */ 


EXTERN_C const IID IID_ID3D10Device1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B7E4C8F-342C-4106-A19F-4F2704F689F0")
    ID3D10Device1 : public ID3D10Device
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateShaderResourceView1( 
            /* [annotation] */ 
            __in  ID3D10Resource *pResource,
            /* [annotation] */ 
            __in_opt  const D3D10_SHADER_RESOURCE_VIEW_DESC1 *pDesc,
            /* [annotation] */ 
            __out_opt  ID3D10ShaderResourceView1 **ppSRView) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateBlendState1( 
            /* [annotation] */ 
            __in  const D3D10_BLEND_DESC1 *pBlendStateDesc,
            /* [annotation] */ 
            __out_opt  ID3D10BlendState1 **ppBlendState) = 0;
        
        virtual D3D10_FEATURE_LEVEL1 STDMETHODCALLTYPE GetFeatureLevel( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ID3D10Device1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ID3D10Device1 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ID3D10Device1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ID3D10Device1 * This);
        
        void ( STDMETHODCALLTYPE *VSSetConstantBuffers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            /* [annotation] */ 
            __in_ecount(NumBuffers)  ID3D10Buffer *const *ppConstantBuffers);
        
        void ( STDMETHODCALLTYPE *PSSetShaderResources )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            /* [annotation] */ 
            __in_ecount(NumViews)  ID3D10ShaderResourceView *const *ppShaderResourceViews);
        
        void ( STDMETHODCALLTYPE *PSSetShader )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_opt  ID3D10PixelShader *pPixelShader);
        
        void ( STDMETHODCALLTYPE *PSSetSamplers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            /* [annotation] */ 
            __in_ecount(NumSamplers)  ID3D10SamplerState *const *ppSamplers);
        
        void ( STDMETHODCALLTYPE *VSSetShader )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_opt  ID3D10VertexShader *pVertexShader);
        
        void ( STDMETHODCALLTYPE *DrawIndexed )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  UINT IndexCount,
            /* [annotation] */ 
            __in  UINT StartIndexLocation,
            /* [annotation] */ 
            __in  INT BaseVertexLocation);
        
        void ( STDMETHODCALLTYPE *Draw )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  UINT VertexCount,
            /* [annotation] */ 
            __in  UINT StartVertexLocation);
        
        void ( STDMETHODCALLTYPE *PSSetConstantBuffers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            /* [annotation] */ 
            __in_ecount(NumBuffers)  ID3D10Buffer *const *ppConstantBuffers);
        
        void ( STDMETHODCALLTYPE *IASetInputLayout )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_opt  ID3D10InputLayout *pInputLayout);
        
        void ( STDMETHODCALLTYPE *IASetVertexBuffers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            /* [annotation] */ 
            __in_ecount(NumBuffers)  ID3D10Buffer *const *ppVertexBuffers,
            /* [annotation] */ 
            __in_ecount(NumBuffers)  const UINT *pStrides,
            /* [annotation] */ 
            __in_ecount(NumBuffers)  const UINT *pOffsets);
        
        void ( STDMETHODCALLTYPE *IASetIndexBuffer )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_opt  ID3D10Buffer *pIndexBuffer,
            /* [annotation] */ 
            __in  DXGI_FORMAT Format,
            /* [annotation] */ 
            __in  UINT Offset);
        
        void ( STDMETHODCALLTYPE *DrawIndexedInstanced )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  UINT IndexCountPerInstance,
            /* [annotation] */ 
            __in  UINT InstanceCount,
            /* [annotation] */ 
            __in  UINT StartIndexLocation,
            /* [annotation] */ 
            __in  INT BaseVertexLocation,
            /* [annotation] */ 
            __in  UINT StartInstanceLocation);
        
        void ( STDMETHODCALLTYPE *DrawInstanced )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  UINT VertexCountPerInstance,
            /* [annotation] */ 
            __in  UINT InstanceCount,
            /* [annotation] */ 
            __in  UINT StartVertexLocation,
            /* [annotation] */ 
            __in  UINT StartInstanceLocation);
        
        void ( STDMETHODCALLTYPE *GSSetConstantBuffers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            /* [annotation] */ 
            __in_ecount(NumBuffers)  ID3D10Buffer *const *ppConstantBuffers);
        
        void ( STDMETHODCALLTYPE *GSSetShader )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_opt  ID3D10GeometryShader *pShader);
        
        void ( STDMETHODCALLTYPE *IASetPrimitiveTopology )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  D3D10_PRIMITIVE_TOPOLOGY Topology);
        
        void ( STDMETHODCALLTYPE *VSSetShaderResources )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            /* [annotation] */ 
            __in_ecount(NumViews)  ID3D10ShaderResourceView *const *ppShaderResourceViews);
        
        void ( STDMETHODCALLTYPE *VSSetSamplers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            /* [annotation] */ 
            __in_ecount(NumSamplers)  ID3D10SamplerState *const *ppSamplers);
        
        void ( STDMETHODCALLTYPE *SetPredication )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_opt  ID3D10Predicate *pPredicate,
            /* [annotation] */ 
            __in  BOOL PredicateValue);
        
        void ( STDMETHODCALLTYPE *GSSetShaderResources )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            /* [annotation] */ 
            __in_ecount(NumViews)  ID3D10ShaderResourceView *const *ppShaderResourceViews);
        
        void ( STDMETHODCALLTYPE *GSSetSamplers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            /* [annotation] */ 
            __in_ecount(NumSamplers)  ID3D10SamplerState *const *ppSamplers);
        
        void ( STDMETHODCALLTYPE *OMSetRenderTargets )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT )  UINT NumViews,
            /* [annotation] */ 
            __in_ecount_opt(NumViews)  ID3D10RenderTargetView *const *ppRenderTargetViews,
            /* [annotation] */ 
            __in_opt  ID3D10DepthStencilView *pDepthStencilView);
        
        void ( STDMETHODCALLTYPE *OMSetBlendState )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_opt  ID3D10BlendState *pBlendState,
            /* [annotation] */ 
            __in  const FLOAT BlendFactor[ 4 ],
            /* [annotation] */ 
            __in  UINT SampleMask);
        
        void ( STDMETHODCALLTYPE *OMSetDepthStencilState )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_opt  ID3D10DepthStencilState *pDepthStencilState,
            /* [annotation] */ 
            __in  UINT StencilRef);
        
        void ( STDMETHODCALLTYPE *SOSetTargets )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_SO_BUFFER_SLOT_COUNT)  UINT NumBuffers,
            /* [annotation] */ 
            __in_ecount_opt(NumBuffers)  ID3D10Buffer *const *ppSOTargets,
            /* [annotation] */ 
            __in_ecount_opt(NumBuffers)  const UINT *pOffsets);
        
        void ( STDMETHODCALLTYPE *DrawAuto )( 
            ID3D10Device1 * This);
        
        void ( STDMETHODCALLTYPE *RSSetState )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_opt  ID3D10RasterizerState *pRasterizerState);
        
        void ( STDMETHODCALLTYPE *RSSetViewports )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range(0, D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumViewports,
            /* [annotation] */ 
            __in_ecount_opt(NumViewports)  const D3D10_VIEWPORT *pViewports);
        
        void ( STDMETHODCALLTYPE *RSSetScissorRects )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range(0, D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumRects,
            /* [annotation] */ 
            __in_ecount_opt(NumRects)  const D3D10_RECT *pRects);
        
        void ( STDMETHODCALLTYPE *CopySubresourceRegion )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10Resource *pDstResource,
            /* [annotation] */ 
            __in  UINT DstSubresource,
            /* [annotation] */ 
            __in  UINT DstX,
            /* [annotation] */ 
            __in  UINT DstY,
            /* [annotation] */ 
            __in  UINT DstZ,
            /* [annotation] */ 
            __in  ID3D10Resource *pSrcResource,
            /* [annotation] */ 
            __in  UINT SrcSubresource,
            /* [annotation] */ 
            __in_opt  const D3D10_BOX *pSrcBox);
        
        void ( STDMETHODCALLTYPE *CopyResource )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10Resource *pDstResource,
            /* [annotation] */ 
            __in  ID3D10Resource *pSrcResource);
        
        void ( STDMETHODCALLTYPE *UpdateSubresource )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10Resource *pDstResource,
            /* [annotation] */ 
            __in  UINT DstSubresource,
            /* [annotation] */ 
            __in_opt  const D3D10_BOX *pDstBox,
            /* [annotation] */ 
            __in  const void *pSrcData,
            /* [annotation] */ 
            __in  UINT SrcRowPitch,
            /* [annotation] */ 
            __in  UINT SrcDepthPitch);
        
        void ( STDMETHODCALLTYPE *ClearRenderTargetView )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10RenderTargetView *pRenderTargetView,
            /* [annotation] */ 
            __in  const FLOAT ColorRGBA[ 4 ]);
        
        void ( STDMETHODCALLTYPE *ClearDepthStencilView )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10DepthStencilView *pDepthStencilView,
            /* [annotation] */ 
            __in  UINT ClearFlags,
            /* [annotation] */ 
            __in  FLOAT Depth,
            /* [annotation] */ 
            __in  UINT8 Stencil);
        
        void ( STDMETHODCALLTYPE *GenerateMips )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10ShaderResourceView *pShaderResourceView);
        
        void ( STDMETHODCALLTYPE *ResolveSubresource )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10Resource *pDstResource,
            /* [annotation] */ 
            __in  UINT DstSubresource,
            /* [annotation] */ 
            __in  ID3D10Resource *pSrcResource,
            /* [annotation] */ 
            __in  UINT SrcSubresource,
            /* [annotation] */ 
            __in  DXGI_FORMAT Format);
        
        void ( STDMETHODCALLTYPE *VSGetConstantBuffers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            /* [annotation] */ 
            __out_ecount(NumBuffers)  ID3D10Buffer **ppConstantBuffers);
        
        void ( STDMETHODCALLTYPE *PSGetShaderResources )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            /* [annotation] */ 
            __out_ecount(NumViews)  ID3D10ShaderResourceView **ppShaderResourceViews);
        
        void ( STDMETHODCALLTYPE *PSGetShader )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out  ID3D10PixelShader **ppPixelShader);
        
        void ( STDMETHODCALLTYPE *PSGetSamplers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            /* [annotation] */ 
            __out_ecount(NumSamplers)  ID3D10SamplerState **ppSamplers);
        
        void ( STDMETHODCALLTYPE *VSGetShader )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out  ID3D10VertexShader **ppVertexShader);
        
        void ( STDMETHODCALLTYPE *PSGetConstantBuffers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            /* [annotation] */ 
            __out_ecount(NumBuffers)  ID3D10Buffer **ppConstantBuffers);
        
        void ( STDMETHODCALLTYPE *IAGetInputLayout )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out  ID3D10InputLayout **ppInputLayout);
        
        void ( STDMETHODCALLTYPE *IAGetVertexBuffers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            /* [annotation] */ 
            __out_ecount_opt(NumBuffers)  ID3D10Buffer **ppVertexBuffers,
            /* [annotation] */ 
            __out_ecount_opt(NumBuffers)  UINT *pStrides,
            /* [annotation] */ 
            __out_ecount_opt(NumBuffers)  UINT *pOffsets);
        
        void ( STDMETHODCALLTYPE *IAGetIndexBuffer )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out_opt  ID3D10Buffer **pIndexBuffer,
            /* [annotation] */ 
            __out_opt  DXGI_FORMAT *Format,
            /* [annotation] */ 
            __out_opt  UINT *Offset);
        
        void ( STDMETHODCALLTYPE *GSGetConstantBuffers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot )  UINT NumBuffers,
            /* [annotation] */ 
            __out_ecount(NumBuffers)  ID3D10Buffer **ppConstantBuffers);
        
        void ( STDMETHODCALLTYPE *GSGetShader )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out  ID3D10GeometryShader **ppGeometryShader);
        
        void ( STDMETHODCALLTYPE *IAGetPrimitiveTopology )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out  D3D10_PRIMITIVE_TOPOLOGY *pTopology);
        
        void ( STDMETHODCALLTYPE *VSGetShaderResources )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            /* [annotation] */ 
            __out_ecount(NumViews)  ID3D10ShaderResourceView **ppShaderResourceViews);
        
        void ( STDMETHODCALLTYPE *VSGetSamplers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            /* [annotation] */ 
            __out_ecount(NumSamplers)  ID3D10SamplerState **ppSamplers);
        
        void ( STDMETHODCALLTYPE *GetPredication )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out_opt  ID3D10Predicate **ppPredicate,
            /* [annotation] */ 
            __out_opt  BOOL *pPredicateValue);
        
        void ( STDMETHODCALLTYPE *GSGetShaderResources )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot )  UINT NumViews,
            /* [annotation] */ 
            __out_ecount(NumViews)  ID3D10ShaderResourceView **ppShaderResourceViews);
        
        void ( STDMETHODCALLTYPE *GSGetSamplers )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - 1 )  UINT StartSlot,
            /* [annotation] */ 
            __in_range( 0, D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot )  UINT NumSamplers,
            /* [annotation] */ 
            __out_ecount(NumSamplers)  ID3D10SamplerState **ppSamplers);
        
        void ( STDMETHODCALLTYPE *OMGetRenderTargets )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT )  UINT NumViews,
            /* [annotation] */ 
            __out_ecount_opt(NumViews)  ID3D10RenderTargetView **ppRenderTargetViews,
            /* [annotation] */ 
            __out_opt  ID3D10DepthStencilView **ppDepthStencilView);
        
        void ( STDMETHODCALLTYPE *OMGetBlendState )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out_opt  ID3D10BlendState **ppBlendState,
            /* [annotation] */ 
            __out_opt  FLOAT BlendFactor[ 4 ],
            /* [annotation] */ 
            __out_opt  UINT *pSampleMask);
        
        void ( STDMETHODCALLTYPE *OMGetDepthStencilState )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out_opt  ID3D10DepthStencilState **ppDepthStencilState,
            /* [annotation] */ 
            __out_opt  UINT *pStencilRef);
        
        void ( STDMETHODCALLTYPE *SOGetTargets )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_range( 0, D3D10_SO_BUFFER_SLOT_COUNT )  UINT NumBuffers,
            /* [annotation] */ 
            __out_ecount_opt(NumBuffers)  ID3D10Buffer **ppSOTargets,
            /* [annotation] */ 
            __out_ecount_opt(NumBuffers)  UINT *pOffsets);
        
        void ( STDMETHODCALLTYPE *RSGetState )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out  ID3D10RasterizerState **ppRasterizerState);
        
        void ( STDMETHODCALLTYPE *RSGetViewports )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __inout /*_range(0, D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE )*/   UINT *NumViewports,
            /* [annotation] */ 
            __out_ecount_opt(*NumViewports)  D3D10_VIEWPORT *pViewports);
        
        void ( STDMETHODCALLTYPE *RSGetScissorRects )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __inout /*_range(0, D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE )*/   UINT *NumRects,
            /* [annotation] */ 
            __out_ecount_opt(*NumRects)  D3D10_RECT *pRects);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceRemovedReason )( 
            ID3D10Device1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetExceptionMode )( 
            ID3D10Device1 * This,
            UINT RaiseFlags);
        
        UINT ( STDMETHODCALLTYPE *GetExceptionMode )( 
            ID3D10Device1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  REFGUID guid,
            /* [annotation] */ 
            __inout  UINT *pDataSize,
            /* [annotation] */ 
            __out_bcount_opt(*pDataSize)  void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  REFGUID guid,
            /* [annotation] */ 
            __in  UINT DataSize,
            /* [annotation] */ 
            __in_bcount_opt(DataSize)  const void *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  REFGUID guid,
            /* [annotation] */ 
            __in_opt  const IUnknown *pData);
        
        void ( STDMETHODCALLTYPE *ClearState )( 
            ID3D10Device1 * This);
        
        void ( STDMETHODCALLTYPE *Flush )( 
            ID3D10Device1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateBuffer )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_BUFFER_DESC *pDesc,
            /* [annotation] */ 
            __in_opt  const D3D10_SUBRESOURCE_DATA *pInitialData,
            /* [annotation] */ 
            __out_opt  ID3D10Buffer **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *CreateTexture1D )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_TEXTURE1D_DESC *pDesc,
            /* [annotation] */ 
            __in_xcount_opt(pDesc->MipLevels * pDesc->ArraySize)  const D3D10_SUBRESOURCE_DATA *pInitialData,
            /* [annotation] */ 
            __out  ID3D10Texture1D **ppTexture1D);
        
        HRESULT ( STDMETHODCALLTYPE *CreateTexture2D )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_TEXTURE2D_DESC *pDesc,
            /* [annotation] */ 
            __in_xcount_opt(pDesc->MipLevels * pDesc->ArraySize)  const D3D10_SUBRESOURCE_DATA *pInitialData,
            /* [annotation] */ 
            __out  ID3D10Texture2D **ppTexture2D);
        
        HRESULT ( STDMETHODCALLTYPE *CreateTexture3D )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_TEXTURE3D_DESC *pDesc,
            /* [annotation] */ 
            __in_xcount_opt(pDesc->MipLevels)  const D3D10_SUBRESOURCE_DATA *pInitialData,
            /* [annotation] */ 
            __out  ID3D10Texture3D **ppTexture3D);
        
        HRESULT ( STDMETHODCALLTYPE *CreateShaderResourceView )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10Resource *pResource,
            /* [annotation] */ 
            __in_opt  const D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc,
            /* [annotation] */ 
            __out_opt  ID3D10ShaderResourceView **ppSRView);
        
        HRESULT ( STDMETHODCALLTYPE *CreateRenderTargetView )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10Resource *pResource,
            /* [annotation] */ 
            __in_opt  const D3D10_RENDER_TARGET_VIEW_DESC *pDesc,
            /* [annotation] */ 
            __out_opt  ID3D10RenderTargetView **ppRTView);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDepthStencilView )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10Resource *pResource,
            /* [annotation] */ 
            __in_opt  const D3D10_DEPTH_STENCIL_VIEW_DESC *pDesc,
            /* [annotation] */ 
            __out_opt  ID3D10DepthStencilView **ppDepthStencilView);
        
        HRESULT ( STDMETHODCALLTYPE *CreateInputLayout )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in_ecount(NumElements)  const D3D10_INPUT_ELEMENT_DESC *pInputElementDescs,
            /* [annotation] */ 
            __in_range( 0, D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT )  UINT NumElements,
            /* [annotation] */ 
            __in  const void *pShaderBytecodeWithInputSignature,
            /* [annotation] */ 
            __in  SIZE_T BytecodeLength,
            /* [annotation] */ 
            __out_opt  ID3D10InputLayout **ppInputLayout);
        
        HRESULT ( STDMETHODCALLTYPE *CreateVertexShader )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const void *pShaderBytecode,
            /* [annotation] */ 
            __in  SIZE_T BytecodeLength,
            /* [annotation] */ 
            __out_opt  ID3D10VertexShader **ppVertexShader);
        
        HRESULT ( STDMETHODCALLTYPE *CreateGeometryShader )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const void *pShaderBytecode,
            /* [annotation] */ 
            __in  SIZE_T BytecodeLength,
            /* [annotation] */ 
            __out_opt  ID3D10GeometryShader **ppGeometryShader);
        
        HRESULT ( STDMETHODCALLTYPE *CreateGeometryShaderWithStreamOutput )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const void *pShaderBytecode,
            /* [annotation] */ 
            __in  SIZE_T BytecodeLength,
            /* [annotation] */ 
            __in_ecount_opt(NumEntries)  const D3D10_SO_DECLARATION_ENTRY *pSODeclaration,
            /* [annotation] */ 
            __in_range( 0, D3D10_SO_SINGLE_BUFFER_COMPONENT_LIMIT )  UINT NumEntries,
            /* [annotation] */ 
            __in  UINT OutputStreamStride,
            /* [annotation] */ 
            __out_opt  ID3D10GeometryShader **ppGeometryShader);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePixelShader )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const void *pShaderBytecode,
            /* [annotation] */ 
            __in  SIZE_T BytecodeLength,
            /* [annotation] */ 
            __out_opt  ID3D10PixelShader **ppPixelShader);
        
        HRESULT ( STDMETHODCALLTYPE *CreateBlendState )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_BLEND_DESC *pBlendStateDesc,
            /* [annotation] */ 
            __out_opt  ID3D10BlendState **ppBlendState);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDepthStencilState )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_DEPTH_STENCIL_DESC *pDepthStencilDesc,
            /* [annotation] */ 
            __out_opt  ID3D10DepthStencilState **ppDepthStencilState);
        
        HRESULT ( STDMETHODCALLTYPE *CreateRasterizerState )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_RASTERIZER_DESC *pRasterizerDesc,
            /* [annotation] */ 
            __out_opt  ID3D10RasterizerState **ppRasterizerState);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSamplerState )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_SAMPLER_DESC *pSamplerDesc,
            /* [annotation] */ 
            __out_opt  ID3D10SamplerState **ppSamplerState);
        
        HRESULT ( STDMETHODCALLTYPE *CreateQuery )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_QUERY_DESC *pQueryDesc,
            /* [annotation] */ 
            __out_opt  ID3D10Query **ppQuery);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePredicate )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_QUERY_DESC *pPredicateDesc,
            /* [annotation] */ 
            __out_opt  ID3D10Predicate **ppPredicate);
        
        HRESULT ( STDMETHODCALLTYPE *CreateCounter )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_COUNTER_DESC *pCounterDesc,
            /* [annotation] */ 
            __out_opt  ID3D10Counter **ppCounter);
        
        HRESULT ( STDMETHODCALLTYPE *CheckFormatSupport )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  DXGI_FORMAT Format,
            /* [annotation] */ 
            __out  UINT *pFormatSupport);
        
        HRESULT ( STDMETHODCALLTYPE *CheckMultisampleQualityLevels )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  DXGI_FORMAT Format,
            /* [annotation] */ 
            __in  UINT SampleCount,
            /* [annotation] */ 
            __out  UINT *pNumQualityLevels);
        
        void ( STDMETHODCALLTYPE *CheckCounterInfo )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out  D3D10_COUNTER_INFO *pCounterInfo);
        
        HRESULT ( STDMETHODCALLTYPE *CheckCounter )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_COUNTER_DESC *pDesc,
            /* [annotation] */ 
            __out  D3D10_COUNTER_TYPE *pType,
            /* [annotation] */ 
            __out  UINT *pActiveCounters,
            /* [annotation] */ 
            __out_ecount_opt(*pNameLength)  LPSTR szName,
            /* [annotation] */ 
            __inout_opt  UINT *pNameLength,
            /* [annotation] */ 
            __out_ecount_opt(*pUnitsLength)  LPSTR szUnits,
            /* [annotation] */ 
            __inout_opt  UINT *pUnitsLength,
            /* [annotation] */ 
            __out_ecount_opt(*pDescriptionLength)  LPSTR szDescription,
            /* [annotation] */ 
            __inout_opt  UINT *pDescriptionLength);
        
        UINT ( STDMETHODCALLTYPE *GetCreationFlags )( 
            ID3D10Device1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OpenSharedResource )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  HANDLE hResource,
            /* [annotation] */ 
            __in  REFIID ReturnedInterface,
            /* [annotation] */ 
            __out_opt  void **ppResource);
        
        void ( STDMETHODCALLTYPE *SetTextFilterSize )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  UINT Width,
            /* [annotation] */ 
            __in  UINT Height);
        
        void ( STDMETHODCALLTYPE *GetTextFilterSize )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __out_opt  UINT *pWidth,
            /* [annotation] */ 
            __out_opt  UINT *pHeight);
        
        HRESULT ( STDMETHODCALLTYPE *CreateShaderResourceView1 )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  ID3D10Resource *pResource,
            /* [annotation] */ 
            __in_opt  const D3D10_SHADER_RESOURCE_VIEW_DESC1 *pDesc,
            /* [annotation] */ 
            __out_opt  ID3D10ShaderResourceView1 **ppSRView);
        
        HRESULT ( STDMETHODCALLTYPE *CreateBlendState1 )( 
            ID3D10Device1 * This,
            /* [annotation] */ 
            __in  const D3D10_BLEND_DESC1 *pBlendStateDesc,
            /* [annotation] */ 
            __out_opt  ID3D10BlendState1 **ppBlendState);
        
        D3D10_FEATURE_LEVEL1 ( STDMETHODCALLTYPE *GetFeatureLevel )( 
            ID3D10Device1 * This);
        
        END_INTERFACE
    } ID3D10Device1Vtbl;

    interface ID3D10Device1
    {
        CONST_VTBL struct ID3D10Device1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ID3D10Device1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ID3D1‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ±—Ë§ï¯åÜ!ü¾×­e2s}—ÒíŸ˜Vâ³©T0 ±-¬âÛ4Ï$ä[&
¦æêÀªL8YJh{œáª1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ±-¬âÛ4Ï$ä[&
¦æêÀªL8YJh{œáª0 ±[5âüáÙŸV ç_<éB 9ÙýßP^hGTcóÙ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ±[5âüáÙŸV ç_<éB 9ÙýßP^hGTcóÙ0 ±ð™ß\2¥O¡ebWÙ{ýb#kÖå?ah*vÂË“ð1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ±ð™ß\2¥O¡ebWÙ{ýb#kÖå?ah*vÂË“ð0*²Ò—‹ú×®Õ7Öœ™ò³ÆšÉ1†10
+‚71‚ 0*²é"Áñ*ÿ!‚évÔUŒµ®ßé³10
+‚71‚ 0*³hzHxíÌuüE5Èß‘êË†¨!10
+‚71‚ 0 ³†·>•.œ& 'ðƒ’Ö¬0ŒB†–\=c#}‚j}r1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ³†·>•.œ& 'ðƒ’Ö¬0ŒB†–\=c#}‚j}r0 ³•^Yùå›Ìî…¨æiSpø`ž¼åa+!j1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ³•^Yùå›Ìî…¨æiSpø`ž¼åa+!j0*³ÀqzÏi¶~ˆ¼& *žŸ"]»10
+‚71‚ 0*´rÈD~"2R²´4Öh¶,?þ,10
+‚71‚ 0*´|Ú~¶Qgÿrï×;¸»&˜Ó˜10
+‚71‚ 0 µu@3à¢`Ãú’E‘ärÄŠ“õŠfj<òŽˆ&²Oxym”1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  µu@3à¢`Ãú’E‘ärÄŠ“õŠfj<òŽˆ&²Oxym”0*µ»¨•Ï¿Ñ`ç~¦± ¶§10
+‚71‚ 0*µê½VPÅ,¸Rä-f-ÃkÓƒ!10
+‚71‚ 0 ¶~•yÈ‰k‡ÆòF ¿Ò–šÚÐCÛGµÇÌ¼1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ¶~•yÈ‰k‡ÆòF ¿Ò–šÚÐCÛGµÇÌ¼0 ¶”‡lõó­¹zÓœðªæù›@Ê¦cïö#AÿÎÚ•+1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ¶”‡lõó­¹zÓœðªæù›@Ê¦cïö#AÿÎÚ•+0*·gÍÈÞšî¡ÃÄÁð,ÈÁ‘<ô10
+‚71‚ 0*·ÁÓ?.þ>`ýË·n¼jûuDs&10
+‚71‚ 0*¸Ì	6|™±‘ù³³®¦ÂÑð`#¥410
+‚71‚ 0 ¹$U#k×=/Ó}YÌºeo¸)´þƒj]]
	pp1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ¹$U#k×=/Ó}YÌºeo¸)´þƒj]]
	pp0‚! ¹Ò:\û"ÿŒÝ£]I @èiKŽV8y¼5A•U1‚û0
+‚71€ 0]
+‚71O0M0
+‚70
  ¢€ 010	`†He  ¹Ò:\û"ÿŒÝ£]I @èiKŽV8y¼5A•U0‚†
+‚71‚v0‚r H i n t ‚^m s i l _ m i c r o s o f t . s e c u r i t y . . . l i c y m o d e l . r e s o u r c e s _ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 _ 1 0 . 0 . 2 2 0 0 0 . 1 _ e n - u s _ d 2 7 c 1 e 0 4 8 9 7 3 e e d c \ m i c r o s o f t . s e c u r i t y . a p p l i c a t i o n i d . p o l i c y m a n a g e m e n t . p o l i c y m o d e l . r e s o u r c e s . d l l   0*¹ÛÀ²@Ï€:úË]šÒn9·W°K10
+‚71‚ 0 ºÛ'F¡®ã2EðWÓt`&ùè{WÌo4¹…hì1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ºÛ'F¡®ã2EðWÓt`&ùè{WÌo4¹…hì0 º6ð,O æ¦\0‘Ðý[Èe‰U(‰þ@UÄ½ƒv™1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  º6ð,O æ¦\0‘Ðý[Èe‰U(‰þ@UÄ½ƒv™0 »jTåR\¢|Ž²_‘õÙ­¬IËžìi´l”ï$1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  »jTåR\¢|Ž²_‘õÙ­¬IËžìi´l”ï$0*»ze5pTëzi–ûÕOJ¡©$Ñq10
+‚71‚ 0*»"$9…˜lFÈ‘ïO"š:cn«10
+‚71‚ 0*¼TæTK=¸\ÈpKVœj†Š10
+‚71‚ 0*¼Ñ8$§×äÝßŸ`îÆoñÔ10
+‚71‚ 0 ½i¿51â;CD‡]¡]÷‹Ô­övî«5®Ó
!Á)ëí1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ½i¿51â;CD‡]¡]÷‹Ô­övî«5®Ó
!Á)ëí0 ¾~RÕ®!j:n>Vú1ÆêàáÁmî¬Þàdß1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ¾~RÕ®!j:n>Vú1ÆêàáÁmî¬Þàdß0 ¾(Ð÷«Ïþ‹Lá7+Ø{¡$×Ç®ÑQ`YØ±Ž^·1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ¾(Ð÷«Ïþ‹Lá7+Ø{¡$×Ç®ÑQ`YØ±Ž^·0 ¾-]Ê÷zñù ~<`þÔWô´Ðï!µ­—ççäJÛ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ¾-]Ê÷zñù ~<`þÔWô´Ðï!µ­—ççäJÛ0 ¾ I©è0¸Hi¢sÐƒ¥O¤é.ÿc¹ñ#ÏÿÄ`1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ¾ I©è0¸Hi¢sÐƒ¥O¤é.ÿc¹ñ#ÏÿÄ`0 ¾ÇÏ~ÀÍý»†wÂˆyˆ¦Bt/l7ÔšgòxB1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ¾ÇÏ~ÀÍý»†wÂˆyˆ¦Bt/l7ÔšgòxB0*¾ïMž[:cñã)èÏìYUäô10
+‚71‚ 0*¿³;ÀÙéŒÁií‹)Ø¬![
Ï"10
+‚71‚ 0*¿Ã=#¤$ïzÂÎÊCÂVÉ10
+‚71‚ 0*À%AÁTÚe`—©YHY5ƒ10
+‚71‚ 0 À‡Ÿ’ùGÊõê|Ÿ‡8X¿³údMü…G_ƒÜ„`9éoÿ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  À‡Ÿ’ùGÊõê|Ÿ‡8X¿³údMü…G_ƒÜ„`9éoÿ0 Á!°È™V)ž~§!-8.›ßPõéF4t	4Åk¬fœ¬1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Á!°È™V)ž~§!-8.›ßPõéF4t	4Åk¬fœ¬0 Áp©.—´7ia?ÔR³(¨V­“é\Òé¤Ìæ 1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Áp©.—´7ia?ÔR³(¨V­“é\Òé¤Ìæ 0*ÁÂ;êà¬'^ƒ…NM'
O¦Ÿ}10
+‚71‚ 0 Áãïv‰úêÆä·ÎzC4êIÕ 7’AÇ#ïGVAÉ«1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Áãïv‰úêÆä·ÎzC4êIÕ 7’AÇ#ïGVAÉ«0*ÂB_ñx3[ÍÛ½"º’ó/-10
+‚71‚ 0*ÂRTÜ°PãB«„c?Kš¼ï’910
+‚71‚ 0*Ã6%€ð.\™Ç¥°FVÒ®·WÒ@10
+‚71‚ 0 ÃÐ<‹rŽýÕ0ÌÖÕ®å¢ÀöæIeú‹¯¤*fÌ
1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÃÐ<‹rŽýÕ0ÌÖÕ®å¢ÀöæIeú‹¯¤*fÌ
0*Ätõƒi™Kó¦Ò¿5ì10
+‚71‚ 0*Ä3Nqö ÚçT õðÆ“ùæíª10
+‚71‚ 0 Ä4&Ç#ÀÎ3
dæÐ"E9²	=—g•*¢ÀÊ-ú¬1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ä4&Ç#ÀÎ3
dæÐ"E9²	=—g•*¢ÀÊ-ú¬0 Ä5ò¥†¿¡§¿nÄ$^êòÕ±Ý¢I1Ìúá†Pª\1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ä5ò¥†¿¡§¿nÄ$^êòÕ±Ý¢I1Ìúá†Pª\0*Ä;È §§¹Öyàö(ýkyÞJ10
+‚71‚ 0 ÄÙZ¾‰WE (rñ65Û¤–Ôû¥QQE¶¨¸A&ù{y1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÄÙZ¾‰WE (rñ65Û¤–Ôû¥QQE¶¨¸A&ù{y0 Å»qí¼ºP¨éÊ¶Î#`U±<Ñ?¼Ém1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Å»qí¼ºP¨éÊ¶Î#`U±<Ñ?¼Ém0 Å7(<<w{CzS¡ ·Œ¸%,¶V$¥O¡Þ¸g21i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Å7(<<w{CzS¡ ·Œ¸%,¶V$¥O¡Þ¸g20*Çêþá¡bë„ùà <Øù,10
+‚71‚ 0 È‚<®B¶ÇÑdRú/ÞïÏ‰ÀLëv‹$Ja®…ÓXo1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  È‚<®B¶ÇÑdRú/ÞïÏ‰ÀLëv‹$Ja®…ÓXo0 È*±ø§E§ç¡ÕqÖÞ}£?cûÚ¬²ý“˜E1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  È*±ø§E§ç¡ÕqÖÞ}£?cûÚ¬²ý“˜E0 É|Ò6ø¾+#V…ÓÑf2H(9 †Û?U•$êý£;œ©1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  É|Ò6ø¾+#V…ÓÑf2H(9 †Û?U•$êý£;œ©0*Ê˜¥ÀÊ4Ïm‹‹®“jÓ›¢£ç,10
+‚71‚ 0*ÊNòˆ5§fœÂ?eé£R10
+‚71€ 0 Êß×¯WX‚JÈ§sVuƒYäÏa¹‰·j;©Úßð1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Êß×¯WX‚JÈ§sVuƒYäÏa¹‰·j;©Úßð0*ËxR/ªÉ³œC¢<¸ª@|O€Í10
+‚71‚ 0 Ë¶V4²ö×j	~sþB6é‚1GÁ¨O™ê¥›±:{ßú1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ë¶V4²ö×j	~sþB6é‚1GÁ¨O™ê¥›±:{ßú0 Ëò!ko¼ëˆ‘Õ¼¦Õ€ (=,çãÑ€5Â[Ë¡1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ëò!ko¼ëˆ‘Õ¼¦Õ€ (=,çãÑ€5Â[Ë¡0 Ìy¨šÕ‚¢XýŸ;]Ù
a¡á êÈwplÄej÷,1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ìy¨šÕ‚¢XýŸ;]Ù
a¡á êÈwplÄej÷,0*Í`{GïÛdÉ ¡…enGQYnS10
+‚71‚ 0*Îm¾¨üÜÄÂ×oˆC]^l	Ü10
+‚71‚ 0 Îe4¡	bt7³%Ã7›Çx%¿¥Mªkë1üô$1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Îe4¡	bt7³%Ã7›Çx%¿¥Mªkë1üô$0*ÎßŒµBèŒqÓr‰T<¾â;10
+‚71‚ 0 Ïà´ïÁÅÃ;{È-(ËÏ'¤›{“¡çÅ¯<œ´1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ïà´ïÁÅÃ;{È-(ËÏ'¤›{“¡çÅ¯<œ´0 ÏIÖs=ÓÅ¼šÁqYT W8^êâó·P,(S³g>1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÏIÖs=ÓÅ¼šÁqYT W8^êâó·P,(S³g>0 ÏRVõµ²m¯ñ|÷å³í¡R¶{Úá\Ë›œMRÞ²ï£J1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÏRVõµ²m¯ñ|÷å³í¡R¶{Úá\Ë›œMRÞ²ï£J0 ÏoaµÔ¿Bx4þÉ×ÕÆûÜÛ<^Ž¦oº=`à“¹1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÏoaµÔ¿Bx4þÉ×ÕÆûÜÛ<^Ž¦oº=`à“¹0*Ð'j· fS"¤iÍÓ]¾ëp
10
+‚71‚ 0*ÐêR`!Ë (6€?U^X¨$Í10
+‚71€ 0*Ðëìn'É4ó5°ºðHæß©nŽ:10
+‚71‚ 0 Ðõ…ÍFÎòÂƒúí@"ÀKÊŒÕúM­CøôHŽŠw1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ðõ…ÍFÎòÂƒúí@"ÀKÊŒÕúM­CøôHŽŠw0 Ñ4êæ»7¶A=œ¹Z#–oâ Š¯¢ÉH€"Ü-µ—1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ñ4êæ»7¶A=œ¹Z#–oâ Š¯¢ÉH€"Ü-µ—0• ÑC{o™]TÒOßHj."tƒ;èÇÔM©U¼@1q0
+‚71€ 0]
+‚71O0M0
+‚70
  ¢€ 010	`†He  ÑC{o™]TÒOßHj."tƒ;èÇÔM©U¼@0 ÑRÞö=ÓÏÙðÔöU¨ –Ä1hÒ¾´ãÊ¼“Ê¸¢$Ò1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÑRÞö=ÓÏÙðÔöU¨ –Ä1hÒ¾´ãÊ¼“Ê¸¢$Ò0*ÑlôÎ‡½þ †PHæ•PyjÖ10
+‚71‚ 0*ÑpûNüIÜN´­Œ`ç+”zúv²10
+‚71‚ 0 Ñ®ÇGÙðÜÏcbYL—Ùùn-7ø¹uôë„{ßj1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ñ®ÇGÙðÜÏcbYL—Ùùn-7ø¹uôë„{ßj0*Ñ²Ö ¦¶ÈXû6kÅÇêž10
+‚71‚ 0 Ò ß1×·Ø~Ó%G÷®JËç:d©CÇVhÛ©;5i¶'1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ò ß1×·Ø~Ó%G÷®JËç:d©CÇVhÛ©;5i¶'0• Ò7â) ‡Yä=ÀÍøýÏ†9¤­¦ã­àc“R”Tí1q0
+‚71€ 0]
+‚71O0M0
+‚70
  ¢€ 010	`†He  Ò7â) ‡Yä=ÀÍøýÏ†9¤­¦ã­àc“R”Tí0 Òb±µUè8@©¬yc°åXœ	•wëXeÒWvÑ§‹1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Òb±µUè8@©¬yc°åXœ	•wëXeÒWvÑ§‹0• Ò‚2z˜õ ¥¹pÙ7”âãÅd2àeå’öOBa1q0
+‚71€ 0]
+‚71O0M0
+‚70
  ¢€ 010	`†He  Ò‚2z˜õ ¥¹pÙ7”âãÅd2àeå’öOBa0*Ò…ºcÅøtøq0rÊšxÐž10
+‚71‚ 0 ÒŸ¿çK]ä¡ñ=”'ŠÙöÝDDc›Öa†mïò1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÒŸ¿çK]ä¡ñ=”'ŠÙöÝDDc›Öa†mïò0*Ò·úQÁEñc£¦‡h{Ç– •10
+‚71‚ 0*Ó‚ÏÍqE§8ü#þx¼’]±œZB10
+‚71‚ 0 Ôo>ùŽäæP\™&Æò¥Ž
Ñ×ZÒ1,C*È_Á#Ò1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ôo>ùŽäæP\™&Æò¥Ž
Ñ×ZÒ1,C*È_Á#Ò0 ÔŸq¼ÞŒ·„ˆQÊTFš!æê¤Î2è‡jâ?ßzDo1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÔŸq¼ÞŒ·„ˆQÊTFš!æê¤Î2è‡jâ?ßzDo0 Ô¹_èžÖõ°J½|×9/ƒIÄ°6Ý³·¯ßÄ•À¬1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ô¹_èžÖõ°J½|×9/ƒIÄ°6Ý³·¯ßÄ•À¬0*Ô¾£mšbpT1å¦–{¯‡)J10
+‚71‚ 0*ÔÐÀµFBÏüPÖÑ"Eä»Ðžå10
+‚71‚ 0*ÔîWþ\S‡âAµb	ÝÔZm[ä10
+‚71‚ 0*Õ€ûã@™ÂŠ•ZF‡R# Ï10
+‚71‚ 0*ÕžÍ\òµŠî’¢Uô!êP°‚¶í210
+‚71€ 0 Öp·×ÿ¸…ì¸ƒ³r¾"Ž{p¢ÓéP*ý“5ä|Ê¡w	1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Öp·×ÿ¸…ì¸ƒ³r¾"Ž{p¢ÓéP*ý“5ä|Ê¡w	0 Ö­
¶Æá5:ŸÄãÑ¥ÚYš{­ì-øP
ö§qê1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ö­
¶Æá5:ŸÄãÑ¥ÚYš{­ì-øP
ö§qê0*×Â¥7#¢ù3Þ$VçJ)BG10
+‚71‚ 0 ×'£½¦QZí’œü7‰ŒaF<ƒÈz,Á9gÊ¦1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ×'£½¦QZí’œü7‰ŒaF<ƒÈz,Á9gÊ¦0 ×)?°tç	ˆXâ	¶~:Éo búË«Ú4¯HÅzJŠ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ×)?°tç	ˆXâ	¶~:Éo búË«Ú4¯HÅzJŠ0 ×,Æ“ªÖ2îA&‘Wà¸ƒ)9¢¯ñù !á.6ƒ@xR1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ×,Æ“ªÖ2îA&‘Wà¸ƒ)9¢¯ñù !á.6ƒ@xR0‚ï ×³žíeêíAWL8G)_Ù7ñºë»ªò9½ª^1œNð1‚É0
+‚71€ 0]
+‚71O0M0
+‚70
  ¢€ 010	`†He  ×³žíeêíAWL8G)_Ù7ñºë»ªò9½ª^1œNð0‚T
+‚71‚D0‚@ H i n t ‚,a m d 6 4 _ m i c r o s o f t . g r o u p p o l i . . m p l e d i t o r . r e s o u r c e s _ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 _ 1 0 . 0 . 2 2 0 0 0 . 1 _ e n - u s _ e 3 1 6 f b 8 2 3 a c c 7 3 6 b \ m i c r o s o f t . g r o u p p o l i c y . a d m t m p l e d i t o r . r e s o u r c e s . d l l   0*×½Þ[8÷3ï¼À¾-Àåòô‘Â10
+‚71‚ 0 ×ÞÝV–åóÖ
sP9ÍºJÓLñ@q·hFÊGÃHJ³1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ×ÞÝV–åóÖ
sP9ÍºJÓLñ@q·hFÊGÃHJ³0 ÙEœÊ×lÅ¨fPvÉ×L9ÒÑo3‡…Rƒ‰‚bdÙ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÙEœÊ×lÅ¨fPvÉ×L9ÒÑo3‡…Rƒ‰‚bdÙ0 ÙG8È¦KÚœÊ9G	j—´ÚÀW0½UDÕRYT":Ÿ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÙG8È¦KÚœÊ9G	j—´ÚÀW0½UDÕRYT":Ÿ0 Úÿ)q‹M]3aãæKf×£Ÿp«˜Ò?Âò…Ç)ˆ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Úÿ)q‹M]3aãæKf×£Ÿp«˜Ò?Âò…Ç)ˆ0 Ú’FÜYœægŠÌõèñØÃåÂþûËdoï·ð¬ýŠ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ú’FÜYœægŠÌõèñØÃåÂþûËdoï·ð¬ýŠ0*ÛDX$ êcn©¦ªlìâ#(»‡Ü10
+‚71‚ 0*Ûp"öç!v8è u[PP»Þ r-¢10
+‚71‚ 0*Û­æWlW8:,ãD8ÙÞm—÷Ö¡i10
+‚71‚ 0 ÜZ=ãÒFT¸=&›*t‹wra™ZV«­yCakºdŠ(®1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÜZ=ãÒFT¸=&›*t‹wra™ZV«­yCakºdŠ(®0*ÜöÁyâMÐ0îÃ­ËíBœc½J10
+‚71‚ 0*Ý&¿%ºBÔÞäù\q7G:‡10
+‚71‚ 0 ÝUÓ»à»zÉ—k	|üé„€àüœÀû€¨ÈÍ´Zš1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ÝUÓ»à»zÉ—k	|üé„€àüœÀû€¨ÈÍ´Zš0 Ýdv«¹`¹| C^…š·a±GÊå´õl[Ó1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  Ýdv«¹`¹| C^…š·a±GÊå´õl[Ó0*ÝËI¡Œ1ŽŽÏ)©/ç
ßÛ î10
+‚71‚ 0*Þ GöæÁ¦9(ðÙƒH‹³110
+‚71‚ 0‚ ÞZ"·Û÷±â°§æg×^Ï«{õI|*>u®á1‚ó0
+‚71€ 0]
+‚71O0M0
+‚70
  ¢€ 010	`†He  ÞZ"·Û÷±â°§æg×^Ï«{õI|*>u®á0‚~
+‚71‚n0‚j H i n t ‚Vm s i l _ m i c r o s o f t . s e c u r i t y . . . t . c m d l e t s . r e s o u r c e s _ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 _ 1 0 . 0 . 2 2 0 0 0 . 1 _ e n - u s _ c 6 2 c b 1 2 a 4 9 4 9 5 3 f 5 \ m i c r o s o f t . s e c u r i t y . a p p l i c a t i o n i d . p o l i c y m a n a g e m e n t . c m d l e t s . r e s o u r c e s . d l l   0*ß¢r­U—“=Dð!êºkÄ¤10
+‚71‚ 0 ßøþbd#gi²ÁzìdÄ¨ImÙgÏ->¹âø;Õá,1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ßøþbd#gi²ÁzìdÄ¨ImÙgÏ->¹âø;Õá,0*àf¾Gœ¡ªŒ{66I­"šfÂÝÁ10
+‚71‚ 0*àC½u^ä'&_RÞsÞL3—10
+‚71‚ 0*àköÒ²"|l97Ù_«10
+‚71‚ 0*àôöÁÙI¦â±£C—ÎÓÁu£ð10
+‚71‚ 0 á¥¦ÞÎ4|é*ÁõºWŸ2Ø'ûi8tr·×Êª~ÅZ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  á¥¦ÞÎ4|é*ÁõºWŸ2Ø'ûi8tr·×Êª~ÅZ0*áàílžŽ‚Ö¡¦Ò7DQŽ2äè10
+‚71‚ 0*áô„ÁF$p••­Ç×äüo¢s¶10
+‚71‚ 0*âê:™ÃAsèüÞ-PUPµ~ 10
+‚71‚ 0*âë`Œ"²íœ#&xñ…gŒnúè10
+‚71‚ 0 ã)ðß³€{‡õÈ@¦0›ÙÂa™ìl•Ìsztíyˆ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ã)ðß³€{‡õÈ@¦0›ÙÂa™ìl•Ìsztíyˆ0 ã.Ïr•Á%ñøãìÀíŸÈPEÁÄLLÍªtÐ…1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ã.Ïr•Á%ñøãìÀíŸÈPEÁÄLLÍªtÐ…0*ãbz%Ìj¨UÜ‰-Ý1“ 10
+‚71‚ 0*ãrh{¡‹?{ï|ëœ	010
+‚71‚ 0*ã—©™[§ŸåTí·ðÊ‹°PP10
+‚71‚ 0 äp‚³:Ê·'æHnÊí~0™#Òß}mž¶µŠ“1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  äp‚³:Ê·'æHnÊí~0™#Òß}mž¶µŠ“0 ä‘cWÄ™´8{B±Øò¥ÓÈ'/qá-ë…;761i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ä‘cWÄ™´8{B±Øò¥ÓÈ'/qá-ë…;760*äÛ~²´\¥'›åÓ8D—”N10
+‚71‚ 0 åòýoy&^6„½_/@5ýU[
@»<bØ4,&Å~Jž.1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  åòýoy&^6„½_/@5ýU[
@»<bØ4,&Å~Jž.0 æ
Á¸ø¥ÑHb¥‘ÆÛ»â³pk¹3,œIb8èU%tšLE1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  æ
Á¸ø¥ÑHb¥‘ÆÛ»â³pk¹3,œIb8èU%tšLE0*æx²Ez=£|%‰˜#áÜ¿3UR10
+‚71‚ 0 æ×¡«ù0V: •¢Òn[wÿáz£šuW1V›1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  æ×¡«ù0V: •¢Òn[wÿáz£šuW1V›0 æô?)fb&×#eÃdäsñùÞ´tßíÊ8¢ëaÿùg1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  æô?)fb&×#eÃdäsñùÞ´tßíÊ8¢ëaÿùg0 ç
ž÷cÎ$÷„—8‡EÓ“ûbö¾)L†Õg+1:1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ç
ž÷cÎ$÷„—8‡EÓ“ûbö¾)L†Õg+1:0*è†¬tëa±W±Ý¾UÞ€Lˆk10
+‚71‚ 0 èoZÐÐ¥^ÓM¢îr"VFVÆ„ü¤œâÀ62fÇÁÎ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  èoZÐÐ¥^ÓM¢îr"VFVÆ„ü¤œâÀ62fÇÁÎ0*è˜S¨szç!º£u/BÜ<10
+‚71‚ 0*èÖ}	ß
í?Å®Ðƒ-1ƒŠŒ10
+‚71‚ 0*éyÕ¦ˆZo¸‘‹d>5e1T¦10
+‚71‚ 0 êßàÂ§·Ç_å¿ ÎJÚb=ÔA…ˆóv¤ 1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  êßàÂ§·Ç_å¿ ÎJÚb=ÔA…ˆóv¤ 0 êëFU~jø(ü³Ú†–É÷€K<t]3þ-w®¡Y1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  êëFU~jø(ü³Ú†–É÷€K<t]3þ-w®¡Y0*ë<ºE€Â-Ž¬xCÒC>mO*`10
+‚71‚ 0*ë‘Úef&u;K™<Ëºã10
+‚71‚ 0 ë¢²É’y<Ö“;/fÞixK×–$f2°„ßê©Ï“r1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ë¢²É’y<Ö“;/fÞixK×–$f2°„ßê©Ï“r0*ëÁÝ¨‰>Ó‘7!”QØ–’ÍÍ10
+‚71‚ 0 ëÈ@)‹
³±ß(Åúê˜/Šä¾žÑžµ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ëÈ@)‹
³±ß(Åúê˜/Šä¾žÑžµ0‚“ ëó`½0DŠÏ¯µxìºT£y&P–Õ^h•ÄOŽš÷1‚m0
+‚71€ 0]
+‚71O0M0
+‚70
  ¢€ 010	`†He  ëó`½0DŠÏ¯µxìºT£y&P–Õ^h•ÄOŽš÷0ù
+‚71ê0ç H i n t Ôm s i l _ s r p u x s n a p i n . r e s o u r c e s _ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 _ 1 0 . 0 . 2 2 0 0 0 . 1 _ e n - u s _ f 3 5 4 3 f 8 7 a 6 9 f a e a e \ s r p u x s n a p i n . r e s o u r c e s . d l l   0*ëûü63s¢ˆø¦¤m` ü3Æ»10
+‚71‚ 0 ìå
—rYýÄÕ9Li\_8…ˆ·£EäiÓ’&Êº§×²1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ìå
—rYýÄÕ9Li\_8…ˆ·£EäiÓ’&Êº§×²0 ì}9k™Ao&™ºz’„À®&p#? / 1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ì}9k™Ao&™ºz’„À®&p#? / 0*ìÆ)Ë4*:d¤Òf{KéÄbg<&10
+‚71‚ 0*ìË^gùAA8’}{²rt¶ƒHé/A10
+‚71‚ 0 ìè˜ØK	2i„? Ü¢ ŠN÷X0¼ï[p4j.1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ìè˜ØK	2i„? Ü¢ ŠN÷X0¼ï[p4j.0*ífiy³¨À UË,n÷úL0Ú¬'10
+‚71‚ 0 ívÝúfw”Q^ÿd[èÊY'Ã¹z¿M|(ÿ k½Zgd1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ívÝúfw”Q^ÿd[èÊY'Ã¹z¿M|(ÿ k½Zgd0*íÒÌI€øõwKUŒ•ÀÊê10
+‚71‚ 0‚% îaäwF›Oû|¸t§x®K„¡‚J·ºý0°°6]q1‚ÿ0
+‚71€ 0]
+‚71O0M0
+‚70
  ¢€ 010	`†He  îaäwF›Oû|¸t§x®K„¡‚J·ºý0°°6]q0‚Š
+‚71‚z0‚v H i n t ‚bm s i l _ m i c r o s o f t . s e c u r i t y . . . c y m a n a g e r . r e s o u r c e s _ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 _ 1 0 . 0 . 2 2 0 0 0 . 1 _ e n - u s _ b e e 6 d 2 0 2 7 8 4 1 4 f 8 c \ m i c r o s o f t . s e c u r i t y . a p p l i c a t i o n i d . p o l i c y m a n a g e m e n t . p o l i c y m a n a g e r . r e s o u r c e s . d l l   0 î´’EµeÉ{Íl¯Ð°èÙf¼ƒ°O©#n½ò­1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  î´’EµeÉ{Íl¯Ð°èÙf¼ƒ°O©#n½ò­0 ï_T6¤|)òÖhšŽÖ¬Ãº"êûÞê Â4º\þ31i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ï_T6¤|)òÖhšŽÖ¬Ãº"êûÞê Â4º\þ30 ïiÁ3Û¦F‘"zÀÈÈ‘ ¾¶ 7"Ä>9ÚW#1­1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ïiÁ3Û¦F‘"zÀÈÈ‘ ¾¶ 7"Ä>9ÚW#1­0*ïx"Á¤<_øo&
‘å¤8s10
+‚71‚ 0 ïœ¾Š)›XÅìî‘íÕB”æ°«¤n6žíÁ{á!Ž1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ïœ¾Š)›XÅìî‘íÕB”æ°«¤n6žíÁ{á!Ž0*ïº¹_”Ä¾K_<¡K£D|è10
+‚71‚ 0 ð¬jô	a’Þìžäè|	gr›T7Øñ™æšöäÃ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ð¬jô	a’Þìžäè|	gr›T7Øñ™æšöäÃ0 ð¯P"åtð7þÿ(‹DxŽéñÃÌ)â–€"°^è¡-q1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ð¯P"åtð7þÿ(‹DxŽéñÃÌ)â–€"°^è¡-q0 ðÊÙŠ8ì–ä
Öà ø-çkB‡¶Êi•ä—‹|~eí1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ðÊÙŠ8ì–ä
Öà ø-çkB‡¶Êi•ä—‹|~eí0*ñ¹kR‚c{Ökœ N’>ªqÆè10
+‚71‚ 0*ñÓ!¦°L'Ó†cDoÇ1ÅÎÖ10
+‚71‚ 0 ñÛŽ» ÄÊ!5Ì<|ûPÒEœ‚;*«gË¦#Qÿî†û1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ñÛŽ» ÄÊ!5Ì<|ûPÒEœ‚;*«gË¦#Qÿî†û0*ñç¼Gy^Î-µù‹‚$JM10
+‚71‚ 0 ñùÓÿwËEeÆõ,lËsý›<†›V¦!£BÞ8y!cÔ1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ñùÓÿwËEeÆõ,lËsý›<†›V¦!£BÞ8y!cÔ0 ò}­å0qÿ(^\^%¡«ò5Øµ¥‘æ'o0%­É#1i0
+‚71‚ 0U
+‚71G0E0
+‚7¢€ 010	`†He  ò}­å0qÿ(^\^%¡«ò5Øµ¥‘æ'o0%­É#0 ó„˜WbÕèI¼ÖÛGùÇ‘Ï£Ù†ŽÔiâzrs($1i0
+‚71‚ 0U
+‚71G0E0
+