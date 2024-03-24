#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"
#include "game/level_update.h"
#include "levels/scripts.h"
#include "actors/common1.h"
#include "make_const_nonconst.h"

#include "areas/1/custom.model.inc.h"

#include "levels/bob/header.h"
#include "levels/bbh/header.h"

extern u8 _bob_segment_ESegmentRomStart[];
extern u8 _bob_segment_ESegmentRomEnd[];

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _bob_segment_ESegmentRomStart, _bob_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom19548816_skybox_mio0SegmentRomStart, _SkyboxCustom19548816_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group3_mio0SegmentRomStart, _group3_mio0SegmentRomEnd),
	LOAD_RAW(12, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd),
	LOAD_MIO0(6, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd),
	LOAD_RAW(13, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR,           haunted_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP,         geo_bbh_0005B0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM,      geo_bbh_0005E0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF,       geo_bbh_000610),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR,          geo_bbh_000628),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND,         geo_bbh_000640),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB,            geo_bbh_000658),
	// Unspecified Models
	LOAD_MODEL_FROM_GEO(22,  warp_pipe_geo),
	LOAD_MODEL_FROM_GEO(23,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(24,  spiky_tree_geo),
	LOAD_MODEL_FROM_GEO(25,  snow_tree_geo),
	LOAD_MODEL_FROM_GEO(27,  palm_tree_geo),
	LOAD_MODEL_FROM_GEO(31,  metal_door_geo),
	LOAD_MODEL_FROM_GEO(32,  hazy_maze_door_geo),
	LOAD_MODEL_FROM_GEO(34,  castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(35,  castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(36,  castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(37,  key_door_geo),
	LOAD_MODEL_FROM_GEO(38,  castle_door_geo),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_4),
	JUMP_LINK(script_func_global_15),
	JUMP_LINK(local_area_bob_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_bob_1_[] = {
	AREA(1, Geo_bob_1_0x12ca9c0),
	TERRAIN(col_bob_1_0xe063d60),
	SET_BACKGROUND_MUSIC(0, 3),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_bob_1_),
	JUMP_LINK(local_warps_bob_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_bob_1_[] = {
	OBJECT_WITH_ACTS(0, 48, 1215, -537, 0, 0, 0, 0x140000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, -695, -83, 10670, 0, 0, 0, 0xc80000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(223, -11, 1730, -2165, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(86, -2129, 4489, 2037, 0, 0, 0, 0x3000000,  bhvKingBobomb, 31),
	OBJECT_WITH_ACTS(100, 2920, -110, -2019, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 2929, -110, -3016, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 1555, -110, -3164, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 551, -91, -3821, 0, 0, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(192, 1132, 4, 132, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -2152, 4, -1805, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 2465, 25, 3960, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(104, -1842, -83, 8015, 0, 0, 0, 0x0,  bhvKoopa, 31),
	OBJECT_WITH_ACTS(0, 2219, 674, 2307, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(122, -669, 1370, 12137, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, -3382, 1, -2367, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1541, 2442, -2169, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1348, 210, 5707, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(215, 4519, 0, 1496, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -2186, 0, -3833, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 2216, 674, 2305, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 2932, 242, 11100, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 552, -83, 14072, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -3447, 0, 1886, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 1184, 61, 1732, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 3687, 0, 5788, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(0, -1446, 1598, 9531, 0, 0, 0, 0x2000000,  bhvHiddenRedCoinStar, 31),
	OBJECT_WITH_ACTS(122, -2924, -1776, 9503, 0, 343, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 4442, 3938, -561, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 1056, 4298, 9658, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(201, 387, 2255, 2431, 0, 180, 0, 0x0,  bhvCannonClosed, 31),
	OBJECT_WITH_ACTS(195, 937, 662, 12787, 0, 0, 0, 0x0,  bhvBobombBuddyOpensCannon, 2),
	OBJECT_WITH_ACTS(0, 2526, 3668, 765, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2127, 0, 1226, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2127, -83, 10456, 0, 321, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 4158, 0, 619, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(140, -6266, 16, -1130, 0, 0, 0, 0x0,  bhvBlueCoinSwitch, 31),
	OBJECT_WITH_ACTS(118, -3958, 1, -1595, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -3478, 2, -1596, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -2979, 3, -1594, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -2477, 4, -1591, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(102, -101, 1, 646, 0, 0, 0, 0x0,  bhvChainChomp, 31),
	OBJECT_WITH_ACTS(0, -179, -83, 13325, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(223, 2111, -110, -2969, 0, 0, 0, 0x0,  bhvChuckya, 31),
	//OBJECT_WITH_ACTS(0, 5, 5, 213, 0, 0, 20, 2,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_bob_1_[] = {
	WARP_NODE(20, 26, 1, 20, 0),
	WARP_NODE(240, 16, 1, 50, 0),
	WARP_NODE(241, 16, 1, 100, 0),
	RETURN()
};