#pragma once

using MouseKeyCode = int;
using KeyCode = int;

#define IC_KEY_UNKNOWN            -1

/* Printable keys */
#define IC_KEY_SPACE              32
#define IC_KEY_APOSTROPHE         39  /* ' */
#define IC_KEY_COMMA              44  /* , */
#define IC_KEY_MINUS              45  /* - */
#define IC_KEY_PERIOD             46  /* . */
#define IC_KEY_SLASH              47  /* / */
#define IC_KEY_0                  48
#define IC_KEY_1                  49
#define IC_KEY_2                  50
#define IC_KEY_3                  51
#define IC_KEY_4                  52
#define IC_KEY_5                  53
#define IC_KEY_6                  54
#define IC_KEY_7                  55
#define IC_KEY_8                  56
#define IC_KEY_9                  57
#define IC_KEY_SEMICOLON          59  /* ; */
#define IC_KEY_EQUAL              61  /* = */
#define IC_KEY_A                  65
#define IC_KEY_B                  66
#define IC_KEY_C                  67
#define IC_KEY_D                  68
#define IC_KEY_E                  69
#define IC_KEY_F                  70
#define IC_KEY_G                  71
#define IC_KEY_H                  72
#define IC_KEY_I                  73
#define IC_KEY_J                  74
#define IC_KEY_K                  75
#define IC_KEY_L                  76
#define IC_KEY_M                  77
#define IC_KEY_N                  78
#define IC_KEY_O                  79
#define IC_KEY_P                  80
#define IC_KEY_Q                  81
#define IC_KEY_R                  82
#define IC_KEY_S                  83
#define IC_KEY_T                  84
#define IC_KEY_U                  85
#define IC_KEY_V                  86
#define IC_KEY_W                  87
#define IC_KEY_X                  88
#define IC_KEY_Y                  89
#define IC_KEY_Z                  90
#define IC_KEY_LEFT_BRACKET       91  /* [ */
#define IC_KEY_BACKSLASH          92  /* \ */
#define IC_KEY_RIGHT_BRACKET      93  /* ] */
#define IC_KEY_GRAVE_ACCENT       96  /* ` */
#define IC_KEY_WORLD_1            161 /* non-US #1 */
#define IC_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define IC_KEY_ESCAPE             256
#define IC_KEY_ENTER              257
#define IC_KEY_TAB                258
#define IC_KEY_BACKSPACE          259
#define IC_KEY_INSERT             260
#define IC_KEY_DELETE             261
#define IC_KEY_RIGHT              262
#define IC_KEY_LEFT               263
#define IC_KEY_DOWN               264
#define IC_KEY_UP                 265
#define IC_KEY_PAIC_UP            266
#define IC_KEY_PAIC_DOWN          267
#define IC_KEY_HOME               268
#define IC_KEY_END                269
#define IC_KEY_CAPS_LOCK          280
#define IC_KEY_SCROLL_LOCK        281
#define IC_KEY_NUM_LOCK           282
#define IC_KEY_PRINT_SCREEN       283
#define IC_KEY_PAUSE              284
#define IC_KEY_F1                 290
#define IC_KEY_F2                 291
#define IC_KEY_F3                 292
#define IC_KEY_F4                 293
#define IC_KEY_F5                 294
#define IC_KEY_F6                 295
#define IC_KEY_F7                 296
#define IC_KEY_F8                 297
#define IC_KEY_F9                 298
#define IC_KEY_F10                299
#define IC_KEY_F11                300
#define IC_KEY_F12                301
#define IC_KEY_F13                302
#define IC_KEY_F14                303
#define IC_KEY_F15                304
#define IC_KEY_F16                305
#define IC_KEY_F17                306
#define IC_KEY_F18                307
#define IC_KEY_F19                308
#define IC_KEY_F20                309
#define IC_KEY_F21                310
#define IC_KEY_F22                311
#define IC_KEY_F23                312
#define IC_KEY_F24                313
#define IC_KEY_F25                314
#define IC_KEY_KP_0               320
#define IC_KEY_KP_1               321
#define IC_KEY_KP_2               322
#define IC_KEY_KP_3               323
#define IC_KEY_KP_4               324
#define IC_KEY_KP_5               325
#define IC_KEY_KP_6               326
#define IC_KEY_KP_7               327
#define IC_KEY_KP_8               328
#define IC_KEY_KP_9               329
#define IC_KEY_KP_DECIMAL         330
#define IC_KEY_KP_DIVIDE          331
#define IC_KEY_KP_MULTIPLY        332
#define IC_KEY_KP_SUBTRACT        333
#define IC_KEY_KP_ADD             334
#define IC_KEY_KP_ENTER           335
#define IC_KEY_KP_EQUAL           336
#define IC_KEY_LEFT_SHIFT         340
#define IC_KEY_LEFT_CONTROL       341
#define IC_KEY_LEFT_ALT           342
#define IC_KEY_LEFT_SUPER         343
#define IC_KEY_RIGHT_SHIFT        344
#define IC_KEY_RIGHT_CONTROL      345
#define IC_KEY_RIGHT_ALT          346
#define IC_KEY_RIGHT_SUPER        347
#define IC_KEY_MENU               348

#define IC_KEY_LAST               IC_KEY_MENU

/*! @} */

/*! @defgroup mods Modifier key flags
 *  @brief Modifier key flags.
 *
 *  See [key input](@ref input_key) for how these are used.
 *
 *  @ingroup input
 *  @{ */

 /*! @brief If this bit is set one or more Shift keys were held down.
  *
  *  If this bit is set one or more Shift keys were held down.
  */
#define IC_MOD_SHIFT           0x0001
  /*! @brief If this bit is set one or more Control keys were held down.
   *
   *  If this bit is set one or more Control keys were held down.
   */
#define IC_MOD_CONTROL         0x0002
   /*! @brief If this bit is set one or more Alt keys were held down.
	*
	*  If this bit is set one or more Alt keys were held down.
	*/
#define IC_MOD_ALT             0x0004
	/*! @brief If this bit is set one or more Super keys were held down.
	 *
	 *  If this bit is set one or more Super keys were held down.
	 */
#define IC_MOD_SUPER           0x0008
	 /*! @brief If this bit is set the Caps Lock key is enabled.
	  *
	  *  If this bit is set the Caps Lock key is enabled and the @ref
	  *  IC_LOCK_KEY_MODS input mode is set.
	  */
#define IC_MOD_CAPS_LOCK       0x0010
	  /*! @brief If this bit is set the Num Lock key is enabled.
	   *
	   *  If this bit is set the Num Lock key is enabled and the @ref
	   *  IC_LOCK_KEY_MODS input mode is set.
	   */
#define IC_MOD_NUM_LOCK        0x0020

	   /*! @} */

	   /*! @defgroup buttons Mouse buttons
		*  @brief Mouse button IDs.
		*
		*  See [mouse button input](@ref input_mouse_button) for how these are used.
		*
		*  @ingroup input
		*  @{ */
#define IC_MOUSE_BUTTON_1         0
#define IC_MOUSE_BUTTON_2         1
#define IC_MOUSE_BUTTON_3         2
#define IC_MOUSE_BUTTON_4         3
#define IC_MOUSE_BUTTON_5         4
#define IC_MOUSE_BUTTON_6         5
#define IC_MOUSE_BUTTON_7         6
#define IC_MOUSE_BUTTON_8         7
#define IC_MOUSE_BUTTON_LAST      IC_MOUSE_BUTTON_8
#define IC_MOUSE_BUTTON_LEFT      IC_MOUSE_BUTTON_1
#define IC_MOUSE_BUTTON_RIGHT     IC_MOUSE_BUTTON_2
#define IC_MOUSE_BUTTON_MIDDLE    IC_MOUSE_BUTTON_3
		/*! @} */

		/*! @defgroup joysticks Joysticks
		 *  @brief Joystick IDs.
		 *
		 *  See [joystick input](@ref joystick) for how these are used.
		 *
		 *  @ingroup input
		 *  @{ */
#define IC_JOYSTICK_1             0
#define IC_JOYSTICK_2             1
#define IC_JOYSTICK_3             2
#define IC_JOYSTICK_4             3
#define IC_JOYSTICK_5             4
#define IC_JOYSTICK_6             5
#define IC_JOYSTICK_7             6
#define IC_JOYSTICK_8             7
#define IC_JOYSTICK_9             8
#define IC_JOYSTICK_10            9
#define IC_JOYSTICK_11            10
#define IC_JOYSTICK_12            11
#define IC_JOYSTICK_13            12
#define IC_JOYSTICK_14            13
#define IC_JOYSTICK_15            14
#define IC_JOYSTICK_16            15
#define IC_JOYSTICK_LAST          IC_JOYSTICK_16
		 /*! @} */

		 /*! @defgroup gamepad_buttons Gamepad buttons
		  *  @brief Gamepad buttons.
		  *
		  *  See @ref gamepad for how these are used.
		  *
		  *  @ingroup input
		  *  @{ */
#define IC_GAMEPAD_BUTTON_A               0
#define IC_GAMEPAD_BUTTON_B               1
#define IC_GAMEPAD_BUTTON_X               2
#define IC_GAMEPAD_BUTTON_Y               3
#define IC_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define IC_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define IC_GAMEPAD_BUTTON_BACK            6
#define IC_GAMEPAD_BUTTON_START           7
#define IC_GAMEPAD_BUTTON_GUIDE           8
#define IC_GAMEPAD_BUTTON_LEFT_THUMB      9
#define IC_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define IC_GAMEPAD_BUTTON_DPAD_UP         11
#define IC_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define IC_GAMEPAD_BUTTON_DPAD_DOWN       13
#define IC_GAMEPAD_BUTTON_DPAD_LEFT       14
#define IC_GAMEPAD_BUTTON_LAST            IC_GAMEPAD_BUTTON_DPAD_LEFT

#define IC_GAMEPAD_BUTTON_CROSS       IC_GAMEPAD_BUTTON_A
#define IC_GAMEPAD_BUTTON_CIRCLE      IC_GAMEPAD_BUTTON_B
#define IC_GAMEPAD_BUTTON_SQUARE      IC_GAMEPAD_BUTTON_X
#define IC_GAMEPAD_BUTTON_TRIANGLE    IC_GAMEPAD_BUTTON_Y
		  /*! @} */

		  /*! @defgroup gamepad_axes Gamepad axes
		   *  @brief Gamepad axes.
		   *
		   *  See @ref gamepad for how these are used.
		   *
		   *  @ingroup input
		   *  @{ */
#define IC_GAMEPAD_AXIS_LEFT_X        0
#define IC_GAMEPAD_AXIS_LEFT_Y        1
#define IC_GAMEPAD_AXIS_RIGHT_X       2
#define IC_GAMEPAD_AXIS_RIGHT_Y       3
#define IC_GAMEPAD_AXIS_LEFT_TRIGICR  4
#define IC_GAMEPAD_AXIS_RIGHT_TRIGICR 5
#define IC_GAMEPAD_AXIS_LAST          IC_GAMEPAD_AXIS_RIGHT_TRIGICR