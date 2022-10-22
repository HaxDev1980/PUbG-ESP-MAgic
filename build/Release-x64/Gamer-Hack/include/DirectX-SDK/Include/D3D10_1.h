

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

#define ID3D1�71� 0U
+�71G0E0
+�7�� 010	`�He  ��˧���!��׭e2s}���ퟘV⳩T0�� �-���4�$�[&
�����L8YJh{���1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �-���4�$�[&
�����L8YJh{���0�� �[5����ٟV��_<�B 9���P^hGTc��1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �[5����ٟV��_<�B 9���P^hGTc��0�� ���\2�O�ebW�{�b#k��?ah*v�˓�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ���\2�O�ebW�{�b#k��?ah*v�˓�0*�җ��׮�7֜�����1�10
+�71� 0*��"��*�!��v�U�����10
+�71� 0*�hzHx��u�E5�ߑ�ˆ�!10
+�71� 0�� ���>�.�&�'���֬0�B��\=c#}�j}r1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ���>�.�&�'���֬0�B��\=c#}�j}r0�� ��^Y�������iSp�`���a+!j1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��^Y�������iSp�`���a+!j0*��qz�i�~��& *��"�]�10
+�71� 0*�r�D~"2R��4�h�,?�,10
+�71� 0*�|�~�Qg�r��;��&�Ӎ�10
+�71� 0�� �u@3�`���E��rĊ���fj<�&�Oxym�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �u@3�`���E��rĊ���fj<�&�Oxym�0*�����Ͽ��`�~�� ��10
+�71� 0*��VP�,�R�-f-�kӃ!10
+�71� 0�� �~�yȉk���F �Җ���C�G�����1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �~�yȉk���F �Җ���C�G�����0�� ���l��zӜ����@ʦc��#A��ڕ+1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ���l��zӜ����@ʦc��#A��ڕ+0*�g��ޚ�����,���<�10
+�71� 0*���?.�>`�˷n�j�uDs&10
+�71� 0*��	6|�����������`#�410
+�71� 0�� �$U#k�=/�}Y̺eo�)���j]]
	pp1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �$U#k�=/�}Y̺eo�)���j]]
	pp0�! ��:\�"��ݣ]I�@�iK�V8y�5A�U1��0
+�71� 0]
+�71O0M0
+�70
���� 010	`�He  ��:\�"��ݣ]I�@�iK�V8y�5A�U0��
+�71�v0�r H i n t �^m s i l _ m i c r o s o f t . s e c u r i t y . . . l i c y m o d e l . r e s o u r c e s _ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 _ 1 0 . 0 . 2 2 0 0 0 . 1 _ e n - u s _ d 2 7 c 1 e 0 4 8 9 7 3 e e d c \ m i c r o s o f t . s e c u r i t y . a p p l i c a t i o n i d . p o l i c y m a n a g e m e n t . p o l i c y m o d e l . r e s o u r c e s . d l l   0*����@π:��]���n9�W�K10
+�71� 0�� ��'F���2E��W�t`&��{W�o4��h�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��'F���2E��W�t`&��{W�o4��h�0�� �6�,O �\0���[�e�U(��@UĽ��v�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �6�,O �\0���[�e�U(��@UĽ��v�0�� �jT�R\�|��_��٭�I˞�i�l��$1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �jT�R\�|��_��٭�I˞�i�l��$0*�ze5pT�zi���OJ��$�q10
+�71� 0*�"$9��lFȑ�O"�:cn�10
+�71� 0*�T�T�K=�\�pKV��j��10
+�71� 0*��8$����ߟ`���o��10
+�71� 0�� �i�51�;CD�]�]��ԭ�v�5��
!�)��1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �i�51�;CD�]�]��ԭ�v�5��
!�)��0�� �~Rծ!j:n>V�1�����m��d�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �~Rծ!j:n>V�1�����m��d�0�� �(������L�7+�{�$����Q`Yر�^�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �(������L�7+�{�$����Q`Yر�^�0�� �-]��z���~<`��W����!������J�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �-]��z���~<`��W����!������J�0�� ��I��0�Hi�s���O��.�c��#���`1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��I��0�Hi�s���O��.�c��#���`0�� ���~�����w��y��Bt/l7Ԛg�xB1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ���~�����w��y��Bt/l7Ԛg�xB0*��M�[:c��)���YU��10
+�71� 0*��;����i�)ج![
�"10
+�71� 0*��=#�$�z���C�V�10
+�71� 0*�%A�T�e`���YHY5�10
+�71� 0�� �����G���|��8X���dM��G_�܄`9�o�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �����G���|��8X���dM��G_�܄`9�o�0�� �!�șV)�~�!-8.��P��F4t	4�k�f��1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �!�șV)�~�!-8.��P��F4t	4�k�f��0�� �p�.��7ia?�R��(�V���\����1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �p�.��7ia?�R��(�V���\����0*��;��'�^��NM'�
O��}10
+�71� 0�� ���v������zC4�I� 7�A�#�GVAɫ1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ���v������zC4�I� 7�A�#�GVAɫ0*�B_�x3[�۽"���/-10
+�71� 0*�RTܰP�B��c?K���910
+�71� 0*�6%��.\�ǥ�FVҮ�W�@10
+�71� 0�� ��<�r���0��ծ����Ie����*f�
1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��<�r���0��ծ����Ie����*f�
0*�t��i�K���5�10
+�71� 0*�3Nq����T ��Ə����10
+�71� 0�� �4&��#��3
d��"E9�	=�g�*���-��1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �4&��#��3
d��"E9�	=�g�*���-��0�� �5򥆿���n�$^��ձݢI1���P�\1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �5򥆿���n�$^��ձݢI1���P�\0*�;� ����y��(�ky�J10
+�71� 0�� ��Z��WE�(r�65ۤ����QQE���A&�{y1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��Z��WE�(r�65ۤ����QQE���A&�{y0�� ��q�P��ʶ��#`U�<�?��m1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��q�P��ʶ��#`U�<�?��m0�� �7(<<w{CzS������%,�V$�O�޸g21i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �7(<<w{CzS������%,�V$�O�޸g20*����b����<���,10
+�71� 0�� ��<�B���dR�/��ω�L�v�$Ja���Xo1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��<�B���dR�/��ω�L�v�$Ja���Xo0�� �*���E���q��}�?c�ڬ����E1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �*���E���q��}�?c�ڬ����E0�� �|�6��+#V���f2H(9 ��?U�$���;��1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �|�6��+#V���f2H(9 ��?U�$���;��0*ʘ���4�m����jӛ���,10
+�71� 0*ʝN�5�f��?e�R10
+�71� 0�� ��ׯWX�JȧsVu�Y��a���j;����1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��ׯWX�JȧsVu�Y��a���j;����0*�xR/�ɳ�C�<��@|O��10
+�71� 0�� ˶V4���j	~s�B6��1G��O�꥛�:{��1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ˶V4���j	~s�B6��1G��O�꥛�:{��0�� ��!ko�눑ռ�Հ�(=,��р5�[ˡ1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��!ko�눑ռ�Հ�(=,��р5�[ˡ0�� �y��Ղ�X��;]��
a����wpl�ej�,1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �y��Ղ�X��;]��
a����wpl�ej�,0*�`{G��d� ��enGQYnS10
+�71� 0*�m�������o�C]^l	�10
+�71� 0�� Νe4�	bt7�%�7��x%��M�k�1��$1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  Νe4�	bt7�%�7��x%��M�k�1��$0*�ߌ��B�q�r�T<��;10
+�71� 0�� ������;{�-(��'��{�����<���1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ������;{�-(��'��{�����<���0�� �I�s=�ż���qYT W8^���P,(S�g>1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �I�s=�ż���qYT W8^���P,(S�g>0�� �RV���m��|���R�{��\˛�MR޲�J1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �RV���m��|���R�{��\˛�MR޲�J0�� �oa�ԿBx4��������<^��o�=`���1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �oa�ԿBx4��������<^��o�=`���0*�'j� fS"�i��]��p
�10
+�71� 0*��R`!� �(6��?U^X�$�10
+�71� 0*���n'�4�5���H�ߩn�:10
+�71� 0�� ����F�����@"�KʌՏ�M�C��H��w1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ����F�����@"�KʌՏ�M�C��H��w0�� �4��7�A=��Z#�o⠊���H�"�-��1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �4��7�A=��Z#�o⠊���H�"�-��0�� �C�{o�]T�O�Hj."t��;���M�U��@1q0
+�71� 0]
+�71O0M0
+�70
���� 010	`�He  �C�{o�]T�O�Hj."t��;���M�U��@0�� �R��=������U����1hҾ��ʼ�ʸ�$�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �R��=������U����1hҾ��ʼ�ʸ�$�0*�l�·�� �PH�Pyj�10
+�71� 0*�p�N�I�N���`�+�z�v�10
+�71� 0�� Ѯ�G����cbYL���n-7��u�넍{�j1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  Ѯ�G����cbYL���n-7��u�넍{�j0*Ѳ�� ���X�6k����10
+�71� 0�� � �1׷�~�%G��J˝�:d�C�Vh۩;5i�'1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  � �1׷�~�%G��J˝�:d�C�Vh۩;5i�'0�� �7�) �Y�=�����φ9�����c�R�T�1q0
+�71� 0]
+�71O0M0
+�70
���� 010	`�He  �7�) �Y�=�����φ9�����c�R�T�0�� �b��U�8@��yc��X�	�w�Xe�Wvѧ�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �b��U�8@��yc��X�	�w�Xe�Wvѧ�0�� ҂2z�� ��p�7�����d2�e��OBa1q0
+�71� 0]
+�71O0M0
+�70
���� 010	`�He  ҂2z�� ��p�7�����d2�e��OBa0*҅�c��t�q0rʚx��10
+�71� 0�� ҟ��K]��=�'����DDc��a�m��1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ҟ��K]��=�'����DDc��a�m��0*ҷ�Q�E��c���h{ǖ��10
+�71� 0*ӂ��qE�8�#�x��]��ZB10
+�71� 0�� �o>����P\�&��
��Z�1,C*�_�#�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �o>����P\�&��
��Z�1,C*�_�#�0�� ԟq������Q��TF�!���2�j�?�zDo1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ԟq������Q��TF�!���2�j�?�zDo0�� Թ_����J�|�9/�Iİ6�����ĕ��1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  Թ_����J�|�9/�Iİ6�����ĕ��0*Ծ�m�b�pT1妖{��)J10
+�71� 0*����FB��P��"E�О�10
+�71� 0*��W�\S��A�b	��Zm[�10
+�71� 0*Հ��@���ZF�R#��10
+�71� 0*՞�\�U�!�P����210
+�71� 0�� �p�����츃�r�"�{p���P*��5�|ʡw	1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �p�����츃�r�"�{p���P*��5�|ʡw	0�� ֭
���5:���ѥ�Y�{��-�P
��q�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ֭
���5:���ѥ�Y�{��-�P
��q�0*�¥7#��3�$V�J)BG10
+�71� 0�� �'���QZ풜��7��aF<��z,�9gʦ1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �'���QZ풜��7��aF<��z,�9gʦ0�� �)?�t�	�X�	�~:��o�b�˫�4�H�zJ�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �)?�t�	�X�	�~:��o�b�˫�4�H�zJ�0�� �,Ɠ��2�A&�Wฃ)9���� !�.6�@xR1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �,Ɠ��2�A&�Wฃ)9���� !�.6�@xR0�� ׳��e��AWL8G)_�7�뻪�9��^1�N�1��0
+�71� 0]
+�71O0M0
+�70
���� 010	`�He  ׳��e��AWL8G)_�7�뻪�9��^1�N�0�T
+�71�D0�@ H i n t �,a m d 6 4 _ m i c r o s o f t . g r o u p p o l i . . m p l e d i t o r . r e s o u r c e s _ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 _ 1 0 . 0 . 2 2 0 0 0 . 1 _ e n - u s _ e 3 1 6 f b 8 2 3 a c c 7 3 6 b \ m i c r o s o f t . g r o u p p o l i c y . a d m t m p l e d i t o r . r e s o u r c e s . d l l   0*׽�[8�3����-������10
+�71� 0�� ���V����
sP9ͺJ�L�@q��hF�G�HJ�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ���V����
sP9ͺJ�L�@q��hF�G�HJ�0�� �E���lŨfPv��L9��o3��R���bd�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �E���lŨfPv��L9��o3��R���bd�0�� �G8��Kڜ�9G	j����W0�UD�RYT":�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �G8��Kڜ�9G	j����W0�UD�RYT":�0�� ��)q�M]3a��Kfף�p���?���)�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��)q�M]3a��Kfף�p���?���)�0�� ڒF�Y��g������������do����1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ڒF�Y��g������������do����0*�DX$ �cn���l��#(���10
+�71� 0*�p"��!v8�u[PP�� r-�10
+�71� 0*ۭ�WlW8:,�D8��m��֡i10
+�71� 0�� �Z=��FT�=&�*t�wra�ZV��yCak�d�(�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �Z=��FT�=&�*t�wra�ZV��yCak�d�(�0*���y�M�0�í��B�c�J10
+�71� 0*�&�%�B����\q7G:�10
+�71� 0�� �Uӻ�zɗk	|�鄀��������ʹZ�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �Uӻ�zɗk	|�鄀��������ʹZ�0�� �dv��`�| C^���a�G����l[Ӎ1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �dv��`�| C^���a�G����l[Ӎ0*��I��1����)�/�
�� �10
+�71� 0*� G����9(���H��110
+�71� 0� �Z"��������g�^��{�I|*>u��1��0
+�71� 0]
+�71O0M0
+�70
���� 010	`�He  �Z"��������g�^��{�I|*>u��0�~
+�71�n0�j H i n t �Vm s i l _ m i c r o s o f t . s e c u r i t y . . . t . c m d l e t s . r e s o u r c e s _ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 _ 1 0 . 0 . 2 2 0 0 0 . 1 _ e n - u s _ c 6 2 c b 1 2 a 4 9 4 9 5 3 f 5 \ m i c r o s o f t . s e c u r i t y . a p p l i c a t i o n i d . p o l i c y m a n a g e m e n t . c m d l e t s . r e s o u r c e s . d l l   0*ߢr�U��=D�!�kĤ10
+�71� 0�� ���bd#gi��z�dĨIm�g�->���;��,1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ���bd#gi��z�dĨIm�g�->���;��,0*�f�G����{66I�"�f���10
+�71� 0*�C�u^�'&_R�s�L3�10
+�71� 0*��k�Ҳ"|l97�_�10
+�71� 0*�����I�ⱣC����u��10
+�71� 0�� ᥦ���4|�*���W�2�'�i8tr��ʪ~�Z1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ᥦ���4|�*���W�2�'�i8tr��ʪ~�Z0*���l���֡��7DQ�2��10
+�71� 0*���F$p�������o�s�10
+�71� 0*��:��As����-PUP�~ 10
+�71� 0*��`�"��#&x�g�n��10
+�71� 0�� �)�߳�{���@�0���a��l��szt�y�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �)�߳�{���@�0���a��l��szt�y�0�� �.�r��%��������PE��LLͪtЅ1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �.�r��%��������PE��LLͪtЅ0*�bz%�j�U܉-�1��10
+�71� 0*�r�h{��?{�|���	010
+�71� 0*㗩�[���T��ʋ�PP10
+�71� 0�� �p��:��'�Hn��~0�#��}m�����1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �p��:��'�Hn��~0�#��}m�����0�� �cW���8{B�����'�/q�-�;761i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �cW���8{B�����'�/q�-�;760*�ۍ~��\�'���8D��N10
+�71� 0�� ���oy&^6��_/@5�U[
@�<b�4,&�~J�.1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ���oy&^6��_/@5�U[
@�<b�4,&�~J�.0�� �
�����Hb���ۻ�pk�3,�Ib8�U%t�LE1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �
�����Hb���ۻ�pk�3,�Ib8�U%t�LE0*�x�Ez=�|%��#�ܿ3UR10
+�71� 0�� �����0�V: ���n[w��z��u�W1V�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �����0�V: ���n[w��z��u�W1V�0�� ��?)fb&�#e�d�s��޴t���8��a��g1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��?)fb&�#e�d�s��޴t���8��a��g0�� �
��c�$���8�Eӓ�b��)L��g+1:1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �
��c�$���8�Eӓ�b��)L��g+1:0*���t�a�W�ݾUހL�k10
+�71� 0�� �oZ�Х^�M���r"VFVƄ������62f���1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �oZ�Х^�M���r"VFVƄ������62f���0*�S�sz�!��u/B��<10
+�71� 0*��}	�
�?ŮЃ-�1���10
+�71� 0*�yզ�Zo���d>5e1T��10
+�71� 0�� ���§��_忠�J�b=�A����v�� 1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ���§��_忠�J�b=�A����v�� 0�� ��FU~j��(��چ����K<t]3�-w��Y1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��FU~j��(��چ����K<t]3�-w��Y0*�<�E��-��xC�C>mO*`10
+�71� 0*둍�ef&u�;K�<���10
+�71� 0�� 뢲ɒy<֓;/f�ixKז$f2����ϓr1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  뢲ɒy<֓;/f�ixKז$f2����ϓr0*�����>ӑ7�!�Qؖ���10
+�71� 0�� ��@)�
���(����/�侞���1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��@)�
���(����/�侞���0�� ��`�0D�ϯ�x�T�y&P��^h��O���1�m0
+�71� 0]
+�71O0M0
+�70
���� 010	`�He  ��`�0D�ϯ�x�T�y&P��^h��O���0��
+�71��0�� H i n t ��m s i l _ s r p u x s n a p i n . r e s o u r c e s _ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 _ 1 0 . 0 . 2 2 0 0 0 . 1 _ e n - u s _ f 3 5 4 3 f 8 7 a 6 9 f a e a e \ s r p u x s n a p i n . r e s o u r c e s . d l l   0*���6�3s�����m`��3ƻ10
+�71� 0�� ��
�rY���9Li\_8����E�iӒ&ʺ�ײ1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��
�rY���9Li\_8����E�iӒ&ʺ�ײ0�� �}9k�Ao&���z�����&p#?�/ 1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �}9k�Ao&���z�����&p#?�/ 0*��)�4*:d��f{K��bg<&10
+�71� 0*��^g�AA8�}{�rt��H�/A10
+�71� 0�� ���K	2i�? ܢ��N�X0��[p4j.�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ���K	2i�? ܢ��N�X0��[p4j.�0*�fiy����U�,n��L0��'10
+�71� 0�� �v��fw�Q^�d[��Y'ùz�M|(� k�Zgd1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �v��fw�Q^�d[��Y'ùz�M|(� k�Zgd0*���I���wKU������10
+�71� 0�% �a�wF�O�|�t�x�K����J���0��6]q1��0
+�71� 0]
+�71O0M0
+�70
���� 010	`�He  �a�wF�O�|�t�x�K����J���0��6]q0��
+�71�z0�v H i n t �bm s i l _ m i c r o s o f t . s e c u r i t y . . . c y m a n a g e r . r e s o u r c e s _ 3 1 b f 3 8 5 6 a d 3 6 4 e 3 5 _ 1 0 . 0 . 2 2 0 0 0 . 1 _ e n - u s _ b e e 6 d 2 0 2 7 8 4 1 4 f 8 c \ m i c r o s o f t . s e c u r i t y . a p p l i c a t i o n i d . p o l i c y m a n a g e m e n t . p o l i c y m a n a g e r . r e s o u r c e s . d l l   0�� E�e�{�l�����f���O�#n��1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  E�e�{�l�����f���O�#n��0�� �_T6�|)��h��֬ú"���� �4��\�31i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �_T6�|)��h��֬ú"���� �4��\�30�� �i�3ۦF�"z��ȑ �� 7"�>9�W#1�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �i�3ۦF�"z��ȑ �� 7"�>9�W#1�0*�x"��<_�o&�
��8s10
+�71� 0�� �)�X�����B�氫�n6���{�!�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �)�X�����B�氫�n6���{�!�0*ﺹ_���K_<�K�D|�10
+�71� 0�� �j�	a�����|	gr�T7������1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �j�	a�����|	gr�T7������0�� �P"�t�7��(�Dx�����)▀"�^�-q1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �P"�t�7��(�Dx�����)▀"�^�-q0�� ��ي8��
�� �-�kB���i����|~e�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ��ي8��
�� �-�kB���i����|~e�0*�kR�c{�k� N�>�q��10
+�71� 0*��!��L'ӆcDo�1���10
+�71� 0�� �ێ����!5́<|�P�E��;*�g˦#Q���1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �ێ����!5́<|�P�E��;*�g˦#Q���0*��G�y^�-�����$JM�10
+�71� 0�� ����w�Ee��,l�s��<��V�!�B�8y!c�1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  ����w�Ee��,l�s��<��V�!�B�8y!c�0�� �}��0q�(^\^%���5ص���'o0%��#1i0
+�71� 0U
+�71G0E0
+�7�� 010	`�He  �}��0q�(^\^%���5ص���'o0%��#0�� ���Wb��I���G�Ǒϣن��i�zrs($1i0
+�71� 0U
+�71G0E0
+