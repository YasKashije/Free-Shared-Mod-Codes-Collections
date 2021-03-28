typedef bool (__fastcall* isPlayer_t)(void*_this);
isPlayer_t  orig_isPlayer = NULL;
bool __fastcall hook_isPlayer(void*_this){

    // Your code here
    // public isMahBoy get_eType

    return orig_isPlayer(_this);
}

typedef int (__fastcall* WeakEnemies_t)(void*_this);
WeakEnemies_t  orig_WeakEnemies = NULL;
int __fastcall hook_WeakEnemies(void*_this){
       
    // Your code here
    // public int get_Attack
    int isMahBoy = orig_isPlayer(_this);
    if(isMahBoy == false)
    {
        return 1;
    }

    return orig_WeakEnemies(_this);
}

typedef int (__fastcall* GodMode_t)(void*_this);
GodMode_t  orig_GodMode = NULL;
int __fastcall hook_GodMode(void*_this){

    // Your code here
    // public int get_Attack
    int isMahBoy = orig_isPlayer(_this);
    if(isMahBoy == true)
    {
        return 999999999;
    }

    return orig_GodMode(_this);
}


void* isPlayer_Ptr = (void *)getRealOffset(0x101FA72DC);
MSHookFunction(isPlayer_Ptr, (void*)&hook_isPlayer, (void**)&orig_isPlayer);
//RYNBattleObject.IsMyHero

void* WeakEnemies_Ptr = (void *)getRealOffset(0x101FA6DA8);
MSHookFunction(WeakEnemies_Ptr, (void*)&hook_WeakEnemies, (void**)&orig_WeakEnemies);
//RYNBattleObject.get_MaxHP

void* GodMode_Ptr = (void *)getRealOffset(0x101FA6D40);
MSHookFunction(GodMode_Ptr, (void*)&hook_GodMode, (void**)&orig_GodMode);
//RYNBattleObject.get_HP
	
//UnitTable
Attack
defence
eType


//Lyn bypass
void (*set_ApplyDamage)(void *_this, long long value) = (void (*)(void *, long long))getRealOffset(0x1023966CC);

void (*AddVerifyDamageList)(void *_this, void* check);
void _AddVerifyDamageList(void *_this, void* check){
  if(check){
    os_log(OS_LOG_DEFAULT,"Added Damage To Verify List - %d",origDamage);
    set_ApplyDamage(check,origDamage);
  }
  AddVerifyDamageList(_this,check);
}

void (*ApplyDamage)(int damageResultType, bool isCritical, int damage, int currentHP, void* actor, bool isNormalAttack, void* skillHitTable, void* skillResultTable, void* valid);
void _ApplyDamage(int damageResultType, bool isCritical, int damage, int currentHP, void* actor, bool isNormalAttack, void* skillHitTable, void* skillResultTable, void* valid){
    origDamage = damage;
    os_log(OS_LOG_DEFAULT,"Orig Damage Recorded - %d",damage);
    // perform heckis here
    ApplyDamage(damageResultType, isCritical, damage, currentHP, actor, isNormalAttack, skillHitTable, skillResultTable, valid);
}

MSHookFunction((void*)getRealOffset(0x10253A9B4), (void*)_ApplyDamage, (void**)&ApplyDamage);
MSHookFunction((void*)getRealOffset(0x101D5ABAC), (void*)_AddVerifyDamageList, (void**)&AddVerifyDamageList);