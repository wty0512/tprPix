/*
 * ======================= ColorTable.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.09.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "ColorTable.h"

//------------------- Engine --------------------//
#include "esrc_time.h"

#include "tprDebug.h"


//============== static ===============//
ID_Manager  ColorTable::id_manager { ID_TYPE::U32, 0};


void CurrentColorTable::update()noexcept{

    if( !this->isWorking ){
            return;
        }
        bool isClose {true}; // find not close enough
        float ProximityRate = 0.05f * 60.0f * 
                            static_cast<float>(esrc::get_timer().get_smoothDeltaTime());

        auto &selfData = this->data.getnc_dataRef();
        const auto &targetData = this->targetColorTablePtr->get_dataRef();

        for( size_t i=0; i<colorTableEntNames.size(); i++ ){

            auto &selfC         = selfData.at(i);
            const auto &targetC = targetData.at(i);
            if( !is_closeEnough(selfC, targetC, 0.001f) ){
                isClose = false;
                selfC += (targetC-selfC) * ProximityRate; //- do close
            }
        }
        if( isClose ){
            this->isWorking = false;
        }
}


void ColorTableSet::debug()noexcept{

    cout << "  === ColorTableSet ===" << endl;
    for( const auto &[iName, iId] : this->name_ids ){

        cout << "  name: " << iName
            << ", colorTableId: " << iId
            << endl;
    }

}

