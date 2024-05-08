This section contains all Sound functions.

# Table Of Contents
* [CP_Sound_Load          ](#cp_sound_load)
* [CP_Sound_LoadMusic     ](#cp_sound_loadmusic)
* [CP_Sound_Free          ](#cp_sound_free)
* [CP_Sound_Play          ](#cp_sound_play)
* [CP_Sound_PlayMusic     ](#cp_sound_playmusic)
* [CP_Sound_PlayAdvanced  ](#cp_sound_playadvanced)
* [CP_Sound_PauseAll      ](#cp_sound_pauseall)
* [CP_Sound_PauseGroup    ](#cp_sound_pausegroup)
* [CP_Sound_ResumeAll     ](#cp_sound_resumeall)
* [CP_Sound_ResumeGroup   ](#cp_sound_resumegroup)
* [CP_Sound_StopAll       ](#cp_sound_stopall)
* [CP_Sound_StopGroup     ](#cp_sound_stopgroup)
* [CP_Sound_SetGroupVolume](#cp_sound_setgroupvolume)
* [CP_Sound_GetGroupVolume](#cp_sound_getgroupvolume)
* [CP_Sound_SetGroupPitch ](#cp_sound_setgrouppitch)
* [CP_Sound_GetGroupPitch ](#cp_sound_getgrouppitch)

# CP_Sound_Load
Load a [CP_Sound](Types.md/#cp_sound) by inputting the file path of the sound file as a string (const char*).

## Function
```C
CP_Sound CP_Sound_Load(const char* filepath);
```

### Parameters
* filepath (const char*) - The path to the sound file that you want to load.

### Return
* [CP_Sound](Types.md#cp_sound) - The loaded sound, returns a NULL CP_Sound if the sound could not be loaded.

## Example
```C
CP_Sound mySound = NULL;

void Init()
{
     mySound = CP_Sound_Load("Assets/Justins_voice.wav");
}

void Update()
{
    if (CP_Input_KeyTriggered(KEY_S))
        CP_Sound_Play(mySound);
}

void Shutdown()
{
    CP_Sound_Free(&mySound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Play](#cp_sound_play)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)

# CP_Sound_LoadMusic
Loads a [CP_Sound](Types.md#cp_sound) from the given file path, and streams the audio from disk while it is playing instead of loading the entire file into memory.

## Function
```C
CP_Sound CP_Sound_LoadMusic(const char* filepath);
```

### Parameters
* filepath (const char*) - The filepath to the music you want to load.

### Return
* [CP_Sound](Types.md#cp_sound) - The music loaded from the given filepath, returns NULL if no music could be loaded.

## Example
```C
CP_Sound mySound = NULL;

void init()
{
    myMusic = CP_Sound_LoadMusic(Assets.mdJustins_Dance_Song.wav");
}

void update()
{
    if (CP_Input_KeyTriggered(KEY_S))
        CP_Sound_PlayMusic(myMusic);
}

void shutdown()
{
     CP_Sound_Free(&myMusic);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_PlayMusic](#cp_sound_playmusic)
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)

# CP_Sound_Free
Frees a given [CP_Sound](Types.md#cp_sound) from memory. The [CP_Sound](Types.md#cp_sound) will not be valid after this call.

## Function
```C
void CP_Sound_Free(CP_Sound* sound);
```

### Parameters
* sound ([CP_Sound](Types.md#cp_sound)) - The sound you want to free.

### Return
This function does not return anything

## Example
```C
CP_Sound mySound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
}

void shutdown()
{
    CP_Sound_Free(&mySound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_Play](#cp_sound_play)

# CP_Sound_Play
Plays a given [CP_Sound](Types.md#cp_sound) once in the [CP_SOUND_GROUP_SFX](Types.md#cp_sound_group) sound group.

## Function
```C
void CP_Sound_Play(CP_Sound sound);
```

### Parameters
* sound ([CP_Sound](Types.md#cp_sound)) - The sound you want to play.

### Return
This function does not return anything.

## Example
```C
CP_Sound mySound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
}

void update()
{
    if (CP_Input_KeyTriggered(KEY_S))
        CP_Sound_Play(mySound);
}

void shutdown()
{
    CP_Sound_Free(&mySound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)

# CP_Sound_PlayMusic
Plays a given [CP_Sound](Types.md#cp_sound) continuously in the [CP_SOUND_GROUP_MUSIC](Types.md#cp_sound_group) sound group. The sound will loop until it is stopped.

## Function
```C
void CP_Sound_PlayMusic(CP_Sound sound);
```

### Parameters
* sound ([CP_Sound](Types.md#cp_sound)) - The sound you want to play as music.

### Return
This function does not return anything.

## Example
```C
CP_Sound mySound = NULL;

void init()
{
    myMusic = CP_Sound_LoadMusic(Assets.mdJustins_voice.wav");
}

void update()
{
    if (CP_Input_KeyTriggered(KEY_S))
        CP_Sound_PlayMusic(myMusic);
}

void shutdown()
{
    CP_Sound_Free(&myMusic);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_LoadMusic](#cp_sound_loadmusic)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)

# CP_Sound_PlayAdvanced
Plays a given [CP_Sound](Types.md#cp_sound) with provided values for the sound's volume and pitch, whether the sound will loop, and the sound group to play it in.

## Function
```C
void CP_Sound_PlayAdvanced(CP_Sound sound, float volume, float pitch, CP_BOOL looping, CP_SOUND_GROUP group);
```

### Parameters
* sound ([CP_Sound](Types.md#cp_sound)) - The sound that you want to play.
* volume (float) - The volume modifier that you want to apply (1.0f = no modification, 0.0 = silent).
* pitch (float) - The pitch modification that you want to apply (1.0f = no modification, 0.5 = half pitch, 2.0 = double pitch).
* looping ([P_BOOL](Types.md#cp_bool)) - If you want the sound to loop or not.
* group ([CP_SOUND_GROUP_MUSIC](Types.md#cp_sound_group)) - The sound group that you want the sound played in.

### Return
This function does not return anything.

## Example
```C
CP_Sound mySound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
}

void update()
{
    if (CP_Input_KeyTriggered(KEY_S))
    {
        // play a sound with double the pitch (1 octave up), looping, and put it in sound group 2
        CP_Sound_PlayAdvanced(mySound, 1.0f, 2.0f, TRUE, CP_SOUND_GROUP_2);
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
}

```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_loadmusic)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)

# CP_Sound_PauseAll
Pauses all [CP_Sounds](Types.md#cp_sound) that are currently playing.

## Function
```C
void CP_Sound_PauseAll();
```

### Parameters
This function has no parameters.

### Return
This function does not return anything.

## Example
```C
CP_Sound mySound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
}

void update()
{
    float songLength = 500;
    static float timer = 0;

    if(!timer)
    {
        CP_Sound_Play(mySound);
    }

    timer += CP_System_GetDt();

    if(timer >= .5f * songLength)
    {
        CP_Sound_PauseAll();
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_Play](#cp_sound_play)
* [CP_System_GetDt](System.md#cp_system_getdt)

# CP_Sound_PauseGroup
Pauses all [CP_Sounds](Types.md#cp_sound) currently playing within the given [CP_SOUND_GROUP](Types.md#cp_sound_group).

## Function
```C
void CP_Sound_PauseGroup(CP_SOUND_GROUP group);
```

### Parameters
* group ([CP_SOUND_GROUP](Types.md#cp_sound_group)) - The sound group that you want to pause.

### Return
This function does not return anything.

## Example
```C
CP_Sound mySound = NULL;
CP_Sound mySecondSound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
    mySecondSound = CP_Sound_Load(Assets.mdJustins_laugh.wav");
}

void update()
{
    float songLength = 500;
    static float timer = 0;

    timer += 1;

    CP_Sound_PlayAdvanced(mySound, 1, 1, TRUE, CP_SOUND_GROUP_3);
    CP_Sound_PlayAdvanced(mySecondSound, 1, 1, TRUE, CP_SOUND_GROUP_5);

    if (timer >= .5f * songLength)
    {
        // this will pause mySound, but not mySecondSound, because mySecondSound is not in CP_SOUND_GROUP_3
        CP_Sound_PauseGroup(CP_SOUND_GROUP_3);
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
    CP_Sound_Free(&mySecondSound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_PlayAdvanced](#cp_sound_playadvanced)

# CP_Sound_ResumeAll
Resumes all [CP_Sounds](Types.md#cp_sound) that are currently paused.

## Function
```C
void CP_Sound_ResumeAll(void);
```

### Parameters
This function has no parameters.

### Return
This function does not return anything.

## Example
```C
CP_Sound mySound = NULL;
CP_Sound mySecondSound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
    mySecondSound = CP_Sound_Load(Assets.mdJustins_laugh.wav");
}

void update()
{
    float songLength = 5;
    static float timer = 0;

    timer += CP_System_GetDt();

    CP_Sound_PlayAdvanced(mySound, 1, 1, TRUE, CP_SOUND_GROUP_3);
    CP_Sound_PlayAdvanced(mySecondSound, 1, 1, TRUE, CP_SOUND_GROUP_5);

    if(timer >= .5f * songLength)
    {
        // this will pause mySound, but not mySecondSound, because mySecondSound is not in CP_SOUND_GROUP_3
        CP_Sound_PauseGroup(CP_SOUND_GROUP_3);
    }

    if(time >= songLength)
    {
        CP_Sound_ResumeAll();  // play any paused sounds
        timer = 0;             // reset the timer so that the sound pauses 50% further in
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
    CP_Sound_Free(&mySecondSound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_PlayAdvanced](#cp_sound_playadvanced)
* [CP_Sound_PauseGroup](#cp_sound_pausegroup)
* [CP_System_GetDt](System.md#cp_system_getdt)

# CP_Sound_ResumeGroup
Resumes all [CP_Sounds](Types.md#cp_sound) that are currently paused within the given [CP_SOUND_GROUP](Types.md#cp_sound_group).

## Function
```C
void CP_Sound_PauseGroup(CP_SOUND_GROUP group);
```

### Parameters
* group ([CP_SOUND_GROUP](Types.md#cp_sound_group)) - The sound group that you want to resume playing.

### Return
This function does not return anything.

## Example
```C
CP_Sound mySound = NULL;
CP_Sound mySecondSound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
    mySecondSound = CP_Sound_Load(Assets.mdJustins_laugh.wav");
}

void update()
{
    float songLength = 5;
    static float timer = 0;

    timer += CP_System_GetDt();

    CP_Sound_PlayAdvanced(mySound, 1, 1, TRUE, CP_SOUND_GROUP_3);
    CP_Sound_PlayAdvanced(mySecondSound, 1, 1, TRUE, CP_SOUND_GROUP_5);

    if(timer >= .5f * songLength)
    {
        // this will pause mySound, but not mySecondSound, because mySecondSound is not in CP_SOUND_GROUP_3
        CP_Sound_PauseGroup(CP_SOUND_GROUP_3);
    }

    if(timer >= songLength)
    {
        CP_Sound_ResumeGroup(CP_SOUND_GROUP_3);  // resume playing all sounds in group 3, currently only mySound
        timer = 0;                               // reset timer so that group 3 pauses another 50% into the timer
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
    CP_Sound_Free(&mySecondSound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_PlayAdvanced](#cp_sound_playadvanced)
* [CP_Sound_ResumeGroup](#cp_sound_resumegroup)
* [CP_System_GetDt](System.md#cp_system_getdt)

# CP_Sound_StopAll
Stops all currently playing [CP_Sounds](Types.md#cp_sound) in all [CP_SOUND_GROUPS](Types.md#cp_sound_group) and resets them to their beginnings.

## Function
```C
void CP_Sound_StopAll(void);
```

### Parameters
This function has no parameters.

### Return
This function does not return anything.

## Example
```C
CP_Sound mySound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
}

void update()
{
    float songLength = 5;
    static float timer = 0;

    timer += CP_System_GetDt();

    CP_Sound_Play(mySound);

    if(timer >= .5f * songLength)
    {
        CP_Sound_StopAll();     // stop playing mySound and reset it to it's beginning
        CP_Sound_Play(mySound); // play mySound from its beginning
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_Play](#cp_sound_play)
* [CP_System_GetDt](System.md#cp_system_getdt)

# CP_Sound_StopGroup
Stops all [CP_Sounds](Types.md#cp_sound) that are currently playing within a given group and resets them to their beginnings.

## Function
```C
void CP_Sound_StopGroup(CP_SOUND_GROUP group);
```

### Parameters
* group ([CP_SOUND_GROUP](Types.md#cp_sound_group)) - The group that you want to stop all sounds in.

### Return
This function does not return anything.

## Example
```C
CP_Sound mySound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
}

void update()
{
    float songLength = 5;
    static float timer = 0;

    timer += CP_System_GetDt();

    CP_Sound_PlayAdvanced(mySound, 1, 1, TRUE, CP_SOUND_GROUP_2); // play a looped, but unedited, mySound in group 2

    if(timer >= .5f * songLength)
    {
        CP_Sound_StopGroup(CP_SOUND_GROUP_2);                         // stop playing mySound and reset it to it's beginning
        CP_Sound_PlayAdvanced(mySound, 1, 1, TRUE, CP_SOUND_GROUP_2); // play mySound from its beginning in group 2
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_PlayAdvanced](#cp_sound_playadvanced)
* [CP_System_GetDt](System.md#cp_system_getdt)

# CP_Sound_SetGroupVolume
Sets the volume of all [CP_Sounds](Types.md#cp_sound) within the given [CP_SOUND_GROUP](Types.md#cp_sound_group).

## Function
```C
void CP_Sound_SetGroupVolume(CP_SOUND_GROUP group, float volume)
```

### Parameters
* group ([CP_SOUND_GROUP](Types.md#cp_sound_group)) - The sound group that you want to set the volume for.
* volume (float) - The volume modifier you want to apply to the group (1.0f is normal volume, 0.0 is silent).

### Return
This function does not return anything.

## Example
```C
CP_Sound mySound = NULL;
CP_Sound mySecondSound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
    mySecondSound = CP_Sound_Load(Assets.mdJustins_laugh.wav");
}

void update()
{
    float songLength = 5;
    static float timer = 0;

    timer += CP_System_GetDt();

    CP_Sound_PlayAdvanced(mySound, 1, 1, TRUE, CP_SOUND_GROUP_3);
    CP_Sound_PlayAdvanced(mySecondSound, 1, 1, TRUE, CP_SOUND_GROUP_5);

    if(timer >= .5f * songLength)
    {
        // make all sounds in group 3 (currently only mySound) half their original volume
        CP_Sound_SetGroupVolume(CP_SOUND_GROUP_3, .5);
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
    CP_Sound_Free(&mySecondSound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_PlayAdvanced](#cp_sound_playadvanced)
* [CP_System_GetDt](System.md#cp_system_getdt)

# CP_Sound_GetGroupVolume
Gets the volume modifier of all [CP_Sounds](Types.md#cp_sound) within the given [CP_SOUND_GROUP](Types.md#cp_sound_group).

## Function
```C
float CP_Sound_GetGroupVolume(CP_SOUND_GROUP group);
```

### Parameters
* group ([CP_SOUND_GROUP](Types.md#cp_sound_group)) - The sound group that you want the volume modifier of.

### Return
* float - The current volume modifier applied to all sounds within the given group.

## Example
```C
CP_Sound mySound = NULL;
CP_Sound mySecondSound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
    mySecondSound = CP_Sound_Load(Assets.mdJustins_laugh.wav");
}

void update()
{
    float songLength = 5;
    static float timer = 0;

    timer += CP_System_GetDt();

    CP_Sound_PlayAdvanced(mySound, 1, 1, TRUE, CP_SOUND_GROUP_3);
    CP_Sound_PlayAdvanced(mySecondSound, 1, 1, TRUE, CP_SOUND_GROUP_5);

    if(timer >= .5f * songLength)
    {
        // set the volume modifier of group 3 to .5
        CP_Sound_SetGroupVolume(CP_SOUND_GROUP_3, .5f);

        // get the modifier of group 3, on the currently .5
        float volume = CP_Sound_GetGroupVolume(CP_SOUND_GROUP_3);
        timer = 0;
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
    CP_Sound_Free(&mySecondSound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_PlayAdvanced](#cp_sound_playadvanced)
* [CP_Sound_SetGroupPitch](#cp_sound_setgrouppitch)
* [CP_System_GetDt](System.md#cp_system_getdt)

# CP_Sound_SetGroupPitch
Sets the pitch modifier of all [CP_Sounds](Types.md#cp_sound) within the given [CP_SOUND_GROUP](Types.md#cp_sound_group).

## Function
```C
void CP_Sound_SetGroupPitch(CP_SOUND_GROUP group, float pitch);
```

### Parameters
* group ([CP_SOUND_GROUP](Types.md#cp_sound_group)) - The sound group that you want to modify the pitch of.
* pitch (float) - The pitch modifier that you want to give to all sounds in the given group (1.0 is normal pitch, 0.5 is half pitch, 2.0 is double pitch).

### Return
This function does not return anything

## Example
```C
CP_Sound mySound = NULL;
CP_Sound mySecondSound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
    mySecondSound = CP_Sound_Load(Assets.mdJustins_laugh.wav");
}

void update()
{
    float songLength = 5;
    static float timer = 0;

    timer += CP_System_GetDt();

    CP_Sound_PlayAdvanced(mySound, 1, 1, TRUE, CP_SOUND_GROUP_3);
    CP_Sound_PlayAdvanced(mySecondSound, 1, 1, TRUE, CP_SOUND_GROUP_5);

    if(timer >= .5f * songLength)
    {
        // set the pitch modifier of group 3 to 2
        CP_Sound_SetGroupPitch(CP_SOUND_GROUP_3, 2);

        // get the pitch modifier of group 3, currently 2.0f
        float pitch = CP_Sound_GetGroupPitch(CP_SOUND_GROUP_3);
        timer = 0;
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
    CP_Sound_Free(&mySecondSound);
}
```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_PlayAdvanced](#cp_sound_playadvanced)
* [CP_Sound_SetGroupPitch](#cp_sound_setgrouppitch)
* [CP_System_GetDt](System.md#cp_system_getdt)

# CP_Sound_GetGroupPitch
Gets the pitch modifier applied to all [CP_Sounds](Types.md#cp_sound) within the given [CP_SOUND_GROUP](Types.md#cp_sound_group).

## Function
```C
float CP_Sound_GetGroupPitch(CP_SOUND_GROUP group);
```

### Parameters
* group ([CP_SOUND_GROUP](Types.md#cp_sound_group)) - The sound group that you want to get the pitch of.

### Return
* float - The current pitch modifier of the specified [CP_SOUND_GROUP](Types.md#cp_sound_group).

## Example
```C
CP_Sound mySound = NULL;
CP_Sound mySecondSound = NULL;

void init()
{
    mySound = CP_Sound_Load(Assets.mdJustins_voice.wav");
    mySecondSound = CP_Sound_Load(Assets.mdJustins_laugh.wav");
}

void update()
{
    float songLength = 5;
    static float timer = 0;

    timer += CP_System_GetDt();

    CP_Sound_PlayAdvanced(mySound, 1, 1, TRUE, CP_SOUND_GROUP_3);
    CP_Sound_PlayAdvanced(mySecondSound, 1, 1, TRUE, CP_SOUND_GROUP_5);

    if(timer >= .5f * songLength)
    {
        // set the pitch modifier of group 3 to 2
        CP_Sound_SetGroupPitch(CP_SOUND_GROUP_3, 2);

        // get the pitch modifier of group 3, on the currently 2.0f
        float pitch = CP_Sound_GetGroupPitch(CP_SOUND_GROUP_3);
        timer = 0;
    }
}

void shutdown()
{
    CP_Sound_Free(&mySound);
    CP_Sound_Free(&mySecondSound);
}

```

## Related
* [CP_Sound](Types.md#cp_sound)
* [CP_Sound_Load](#cp_sound_load)
* [CP_Sound_Free](#cp_sound_free)
* [CP_Sound_PlayAdvanced](#cp_sound_playadvanced)
* [CP_Sound_SetGroupPitch](#cp_sound_setgrouppitch)
* [CP_System_GetDt](System.md#cp_system_getdt)
