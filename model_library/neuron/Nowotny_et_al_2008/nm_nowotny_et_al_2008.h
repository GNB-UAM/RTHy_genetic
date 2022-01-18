/**
 * @file nm_nowotny_et_al_2008.h
 * @brief Header file for the Nowotny_et_al_2008 model functions.
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NM_NOWOTNY_ET_AL_2008_H__
#define NM_NOWOTNY_ET_AL_2008_H__

#include <math.h>
#include "../../../clamp/includes/types_clamp.h"

/** @name Nowotny_et_al_2008
 * Nowotny_et_al_2008 neuron model.
 */
///@{

#define NM_NOWOTNY_ET_AL_2008_N_VARS 16
// Variables
#define NM_NOWOTNY_ET_AL_2008_V 0
#define NM_NOWOTNY_ET_AL_2008_MNA 1
#define NM_NOWOTNY_ET_AL_2008_HNA 2
#define NM_NOWOTNY_ET_AL_2008_MKD 3
#define NM_NOWOTNY_ET_AL_2008_MM 4
#define NM_NOWOTNY_ET_AL_2008_VAXON 5
#define NM_NOWOTNY_ET_AL_2008_MCAT 6
#define NM_NOWOTNY_ET_AL_2008_HCAT 7
#define NM_NOWOTNY_ET_AL_2008_MCAS 8
#define NM_NOWOTNY_ET_AL_2008_CA 9
#define NM_NOWOTNY_ET_AL_2008_MKCA 10
#define NM_NOWOTNY_ET_AL_2008_HKCA 11
#define NM_NOWOTNY_ET_AL_2008_MA 12
#define NM_NOWOTNY_ET_AL_2008_HA1 13
#define NM_NOWOTNY_ET_AL_2008_HA2 14
#define NM_NOWOTNY_ET_AL_2008_MH 15


#define NM_NOWOTNY_ET_AL_2008_N_PARAMS 75
// Parameters
#define NM_NOWOTNY_ET_AL_2008_DT 0
#define NM_NOWOTNY_ET_AL_2008_GNA 1
#define NM_NOWOTNY_ET_AL_2008_VNA 2
#define NM_NOWOTNY_ET_AL_2008_AREAAXON 3
#define NM_NOWOTNY_ET_AL_2008_GKD 4
#define NM_NOWOTNY_ET_AL_2008_VKD 5
#define NM_NOWOTNY_ET_AL_2008_GM 6
#define NM_NOWOTNY_ET_AL_2008_VM 7
#define NM_NOWOTNY_ET_AL_2008_VMM 8
#define NM_NOWOTNY_ET_AL_2008_SMM 9
#define NM_NOWOTNY_ET_AL_2008_KMM 10
#define NM_NOWOTNY_ET_AL_2008_VKMM 11
#define NM_NOWOTNY_ET_AL_2008_SKMM 12
#define NM_NOWOTNY_ET_AL_2008_GLA 13
#define NM_NOWOTNY_ET_AL_2008_VL 14
#define NM_NOWOTNY_ET_AL_2008_GVV 15
#define NM_NOWOTNY_ET_AL_2008_CMA 16
#define NM_NOWOTNY_ET_AL_2008_GCAT 17
#define NM_NOWOTNY_ET_AL_2008_GCAS 18
#define NM_NOWOTNY_ET_AL_2008_PCA 19
#define NM_NOWOTNY_ET_AL_2008_RTF 20
#define NM_NOWOTNY_ET_AL_2008_CAOUT 21
#define NM_NOWOTNY_ET_AL_2008_AREASOMA 22
#define NM_NOWOTNY_ET_AL_2008_VMCAT 23
#define NM_NOWOTNY_ET_AL_2008_SMCAT 24
#define NM_NOWOTNY_ET_AL_2008_KMCAT 25
#define NM_NOWOTNY_ET_AL_2008_VHCAT 26
#define NM_NOWOTNY_ET_AL_2008_SHCAT 27
#define NM_NOWOTNY_ET_AL_2008_KHCAT 28
#define NM_NOWOTNY_ET_AL_2008_VKHCAT 29
#define NM_NOWOTNY_ET_AL_2008_SKHCAT 30
#define NM_NOWOTNY_ET_AL_2008_VMCAS 31
#define NM_NOWOTNY_ET_AL_2008_SMCAS 32
#define NM_NOWOTNY_ET_AL_2008_KMCAS 33
#define NM_NOWOTNY_ET_AL_2008_CICA 34
#define NM_NOWOTNY_ET_AL_2008_KCA 35
#define NM_NOWOTNY_ET_AL_2008_CA0 36
#define NM_NOWOTNY_ET_AL_2008_GKCA 37
#define NM_NOWOTNY_ET_AL_2008_VKCA 38
#define NM_NOWOTNY_ET_AL_2008_VMKCA1 39
#define NM_NOWOTNY_ET_AL_2008_F 40
#define NM_NOWOTNY_ET_AL_2008_SMKCA1 41
#define NM_NOWOTNY_ET_AL_2008_VMKCA2 42
#define NM_NOWOTNY_ET_AL_2008_SMKCA2 43
#define NM_NOWOTNY_ET_AL_2008_CMKCA 44
#define NM_NOWOTNY_ET_AL_2008_KMKCA 45
#define NM_NOWOTNY_ET_AL_2008_CHKCA1 46
#define NM_NOWOTNY_ET_AL_2008_CHKCA2 47
#define NM_NOWOTNY_ET_AL_2008_KHKCA 48
#define NM_NOWOTNY_ET_AL_2008_GA 49
#define NM_NOWOTNY_ET_AL_2008_VA 50
#define NM_NOWOTNY_ET_AL_2008_VAA 51
#define NM_NOWOTNY_ET_AL_2008_SAA 52
#define NM_NOWOTNY_ET_AL_2008_VMA 53
#define NM_NOWOTNY_ET_AL_2008_SMA 54
#define NM_NOWOTNY_ET_AL_2008_KMA 55
#define NM_NOWOTNY_ET_AL_2008_VHA 56
#define NM_NOWOTNY_ET_AL_2008_SHA 57
#define NM_NOWOTNY_ET_AL_2008_KHA1 58
#define NM_NOWOTNY_ET_AL_2008_KHA2 59
#define NM_NOWOTNY_ET_AL_2008_VKHA2 60
#define NM_NOWOTNY_ET_AL_2008_SKHA2 61
#define NM_NOWOTNY_ET_AL_2008_GH 62
#define NM_NOWOTNY_ET_AL_2008_VH 63
#define NM_NOWOTNY_ET_AL_2008_VMH 64
#define NM_NOWOTNY_ET_AL_2008_SMH 65
#define NM_NOWOTNY_ET_AL_2008_KMH 66
#define NM_NOWOTNY_ET_AL_2008_VKMH 67
#define NM_NOWOTNY_ET_AL_2008_SKMH 68
#define NM_NOWOTNY_ET_AL_2008_GLS 69
#define NM_NOWOTNY_ET_AL_2008_I 70
#define NM_NOWOTNY_ET_AL_2008_IOFFSET 71
#define NM_NOWOTNY_ET_AL_2008_SYN 72
#define NM_NOWOTNY_ET_AL_2008_ISCALE 73
#define NM_NOWOTNY_ET_AL_2008_CMS 74

void nm_nowotny_et_al_2008_init (neuron_model * nm, double * vars, double * params);
void nm_nowotny_et_al_2008_ (neuron_model nm, double syn);
double nm_nowotny_et_al_2008_set_pts_burst (double pts_live, neuron_model * nm);

///@}

#endif // NM_NOWOTNY_ET_AL_2008_H__

#ifdef __cplusplus
}
#endif