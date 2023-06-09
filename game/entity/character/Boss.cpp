//
// Created by theo on 17/05/23.
//

#include "Boss.h"

#include "Hero.h"
#include <rdlib/Time.h>
#include "FXAgent.h"
#include "BossMeteor.h"
#include "../../GameWin.h"
#include "GroundSlamFx.h"

Boss::Boss(vec3 position, void(*callback)()) : Monster("assets/character/boss.png", position, vec2(3, 3), vec3(1, 1, 1),
                                                       100, 10,
                                                       vec2(1 / 3.0, 0), vec2(1 / 3.0, 2 / 4.0)) {
    m_callback = callback;
    m_lifetime = 0;
    m_speed = 3;
}

void Boss::update() {
    //auto hero = Agent::getObjectsOfType<Hero>();
    //if (!hero.empty()) {
    //    auto hero_pos = hero[0]->getPos();
    //    auto hero_dir = glm::normalize(hero_pos - getPos());
    //    auto hero_dist = glm::distance(hero_pos, getPos());
    //    if (hero_dist < 5 || m_triggered) {
    //        m_triggered = true;
    //        m_hero_direction = hero_dir;
    //        m_speed = 3;
    //    } else {
    //        m_speed = 0;
    //    }
    //}

    // We had bugs with the player detection, so we just trigger the boss
    // He can't move far so it's not really a problem
    m_triggered = true;

    if (m_triggered) {

        if (m_lifetime < 2) {
            if (m_lifetime < 0.5) {
                m_pos += vec3(1, 0, 0) * m_speed * rdlib::Time::getDelta();
            } else if (m_lifetime < 1.5) {
                m_pos -= vec3(1, 0, 0) * m_speed * rdlib::Time::getDelta();
            } else {
                m_pos += vec3(1, 0, 0) * m_speed * rdlib::Time::getDelta();
            }
            m_stage = 1;

        } else if (m_lifetime < 4) {
            if (m_stage != 2) {
                if (m_lifetime > 2.8 && m_lifetime < 2.9) {
                    m_pos += vec3(0, 1, 0) * m_speed * rdlib::Time::getDelta();
                } else if (m_lifetime < 3 && m_lifetime > 2.9) {
                    m_pos -= vec3(0, 1, 0) * m_speed * rdlib::Time::getDelta();
                } else if (m_lifetime > 3) {
                    new GroundSlamFx(getPos() + vec3(0, -1, 1));


                    // if the hero is in range, damage him
                    auto hero = Agent::getObjectsOfType<Hero>();
                    if (!hero.empty()) {
                        auto hero_pos = hero[0]->getPos();
                        auto hero_dist = glm::distance(hero_pos, getPos());
                        if (hero_dist < 3) {
                            std::cout << "hero hit" << std::endl;
                            hero[0]->setPv(hero[0]->getPv() - 10);
                        }
                    }
                    m_stage = 2;
                }
            }
        } else if (m_lifetime < 6) {
            if (m_stage != 3) {
                if (m_lifetime > 4.8 && m_lifetime < 4.9) {
                    m_pos += vec3(0, 1, 0) * m_speed * rdlib::Time::getDelta();
                } else if (m_lifetime < 5 && m_lifetime > 4.9) {
                    m_pos -= vec3(0, 1, 0) * m_speed * rdlib::Time::getDelta();
                } else if (m_lifetime > 5) {
                    // Create 10 meteors in a circle around the player
                    for (int i = 0; i < 40; i++) {
                        // Create the target position
                        // A random vec3 of length between 3 and 5
                        // use rand()
                        auto target = vec3(rand() % 100 - 50, rand() % 100 - 50, 0);
                        float length = (rand() % 100 - 50) / 100.0 * 2.0 + 3.0;
                        target = glm::normalize(target) * length;
                        target += getPos() - vec3(0, 1, 0);

                        auto origin = target + vec3(0, 10, 0);
                        new BossMeteor(origin, target, 1);
                    }

                    m_stage = 3;
                }
            }
        }
    }

    m_lifetime += rdlib::Time::getDelta();
    m_lifetime = fmod(m_lifetime, 6);

    if (getPv() <= 0) {
        new GameWin(m_callback);

        FXAgent::fx(m_pos - vec3(0, 1, 0), .5);
        kill();
    }
}
