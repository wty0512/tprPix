/*
 * ========================= config.h ==========================
 *                          -- tpr --
 *                                        创建 -- 2018.11.21
 *                                        修改 -- 2018.11.21
 * ----------------------------------------------------------
 *   配置 参数
 * ----------------------------
 */

#ifndef _TPR_CONFIG_H_
#define _TPR_CONFIG_H_

//-- window 显示尺寸（像素）--
#define SCR_WIDTH  880
#define SCR_HEIGHT  660

//-- 游戏工作尺寸（像素）--
//- 由于是 pixel游戏，所以这个值会很小。
//- 这个值 也是 Camera 的尺寸
#define WORK_WIDTH  160
#define WORK_HEIGHT 120

//-- 是否开启 全屏模式 --
inline bool IS_FULL_SCREEN = false; 



#endif






