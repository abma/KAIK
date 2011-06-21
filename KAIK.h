#ifndef KAIK_GLOBALAI_HDR
#define KAIK_GLOBALAI_HDR

#include <fstream>

#include "System/float3.h"
#include "IncExternAI.h"

struct AIClasses;

class CKAIK: public IGlobalAI {
	public:
		CR_DECLARE(CKAIK);

		CKAIK(): ai(NULL) {}
		~CKAIK() {}

		void InitAI(IGlobalAICallback* callback, int team);
		void ReleaseAI();

		void UnitCreated(int unit, int builder);
		void UnitFinished(int unit);
		void UnitDestroyed(int unit, int attacker);
		void UnitIdle(int unit);
		void UnitDamaged(int damaged, int attacker, float damage, float3 dir);
		void EnemyDamaged(int damaged, int attacker, float damage, float3 dir);
		void UnitMoveFailed(int unit);

		void EnemyEnterLOS(int enemy);
		void EnemyLeaveLOS(int enemy);
		void EnemyEnterRadar(int enemy);
		void EnemyLeaveRadar(int enemy);
		void EnemyDestroyed(int enemy, int attacker);
		void EnemyCreated(int enemy);
		void EnemyFinished(int enemy);

		void RecvChatMessage(const char* msg, int player);
		void RecvLuaMessage(const char* inData, const char** outData);
		int HandleEvent(int msg, const void* data);

		void Update();

		#ifdef USING_CREG
		void Load(IGlobalAICallback* callback, std::istream* ifs);
		void Save(std::ostream* ofs);
		void PostLoad(void);
		void Serialize(creg::ISerializer* s);
		#endif

		AIClasses* GetAI() const { return ai; }

	private:
		AIClasses* ai;
};

#endif
