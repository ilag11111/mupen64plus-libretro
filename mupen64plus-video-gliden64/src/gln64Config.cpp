#ifdef OS_WINDOWS
# include <windows.h>
#else
# include "winlnxdefs.h"
#endif // OS_WINDOWS
#include "RSP.h"
#include "PluginAPI.h"
#include "Config.h"
#include "wst.h"

Config config;

void Config::resetToDefaults()
{
	version = CONFIG_VERSION_CURRENT;

#if defined(PANDORA) || defined(VC)
	video.fullscreen = 1;
	video.fullscreenWidth = video.windowedWidth = 800;
#else
	video.fullscreen = 0;
	video.fullscreenWidth = video.windowedWidth = 640;
#endif
	video.fullscreenHeight = video.windowedHeight = 480;
	video.fullscreenRefresh = 60;
	video.multisampling = 0;
	video.verticalSync = 0;

	texture.maxAnisotropy = 0;
	texture.bilinearMode = BILINEAR_STANDARD;
	texture.maxBytes = 500 * gc_uMegabyte;
	texture.screenShotFormat = 0;

	generalEmulation.enableFog = 1;
	generalEmulation.enableLOD = 1;
	generalEmulation.enableNoise = 1;
	generalEmulation.enableHWLighting = 0;
	generalEmulation.enableCustomSettings = 1;
	generalEmulation.enableShadersStorage = 1;
	generalEmulation.hacks = 0;
#ifdef ANDROID
	generalEmulation.forcePolygonOffset = 0;
	generalEmulation.polygonOffsetFactor = 0.0f;
	generalEmulation.polygonOffsetUnits = 0.0f;
#endif

	frameBufferEmulation.enable = 1;
	frameBufferEmulation.copyDepthToRDRAM = ctDisable;
	frameBufferEmulation.copyFromRDRAM = 0;
	frameBufferEmulation.copyAuxToRDRAM = 0;
	frameBufferEmulation.copyToRDRAM = ctAsync;
	frameBufferEmulation.N64DepthCompare = 0;
	frameBufferEmulation.aspect = 1;
	frameBufferEmulation.bufferSwapMode = bsOnVerticalInterrupt;

	textureFilter.txCacheSize = 100 * gc_uMegabyte;
	textureFilter.txDump = 0;
	textureFilter.txEnhancementMode = 0;
	textureFilter.txFilterIgnoreBG = 0;
	textureFilter.txFilterMode = 0;
	textureFilter.txHiresEnable = 0;
	textureFilter.txHiresFullAlphaChannel = 0;
	textureFilter.txHresAltCRC = 0;

	textureFilter.txCacheCompression = 1;
	textureFilter.txForce16bpp = 0;
	textureFilter.txSaveCache = 1;

	//api().GetUserDataPath(textureFilter.txPath);
	gln_wcscat(textureFilter.txPath, wst("/hires_texture"));

	bloomFilter.enable = 0;
	bloomFilter.thresholdLevel = 4;
	bloomFilter.blendMode = 0;
	bloomFilter.blurAmount = 10;
	bloomFilter.blurStrength = 20;

	gammaCorrection.force = 0;
	gammaCorrection.level = 2.0f;
}