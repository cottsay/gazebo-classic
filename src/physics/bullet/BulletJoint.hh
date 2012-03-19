/*
 * Copyright 2011 Nate Koenig & Andrew Howard
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
/* Desc: The base Bullet joint class
 * Author: Nate Keonig, Andrew Howard
 * Date: 21 May 2003
 */

#ifndef BULLETJOINT_HH
#define BULLETJOINT_HH

/*
#include <btBulletDynamicsCommon.h>

#include "common/Console.hh"
#include "Joint.hh"
#include "math/Vector3.hh"
*/

namespace gazebo
{
  namespace physics
  {
    /// \addtogroup gazebo_physics
    /// \brief Base class for all joints
    /// \{
    /// \brief Base class for all joints
    class BulletJoint : public Joint
    {
      /// \brief Constructor
      public: BulletJoint();

      /// \brief Destructor
      public: virtual ~BulletJoint();

      /// \brief Load a joint
      public: void Load(common::XMLConfigNode *node);

      /// \brief Update the joint
      public: void Update();

      /// \brief Reset the joint
      public: void Reset() {}

      /// \brief Get the body to which the joint is attached
      ///        according the _index
      public: Link *GetJointLink(int index) const;

      /// \brief Determines of the two bodies are connected by a joint
      public: bool AreConnected(Link *one, Link *two) const;

      /// \brief Detach this joint from all bodies
      public: virtual void Detach();

      /// \brief Set the anchor point
      public: virtual void SetAnchor(int /*index*/,
                                      const gazebo::math::Vector3 & /*anchor*/)
              {gzerr << "Not implement in Bullet\n";}
      /// \brief Set the joint damping
      public: virtual void SetDamping(int /*index*/,
                                      const double /*damping*/)
              {gzerr << "Not implement in Bullet\n";}
      /// \brief Get the anchor point
      public: virtual gazebo::math::Vector3 GetAnchor(int index) const
              {gzerr << "Not implement in Bullet\n";
               return math::Vector3();}
      /// \brief Get the force the joint applies to the first body
      /// \param index The index of the body(0 or 1)
      public: virtual math::Vector3 GetLinkForce(unsigned int index) const
              {gzerr << "Not implement in Bullet\n";
               return math::Vector3();}
      /// \brief Get the torque the joint applies to the first body
      /// \param index The index of the body(0 or 1)
      public: virtual math::Vector3 GetLinkTorque(unsigned int index) const
              {gzerr << "Not implement in Bullet\n";
               return math::Vector3();}
      /// \brief Set a parameter for the joint
      public: virtual void SetAttribute(Attribute, int index, double value)
              {gzerr << "Not implement in Bullet\n";}
      /// \brief Set the ERP of this joint
      public: void SetERP(double newERP);

      /// \brief Get the ERP of this joint
      public: double GetERP();

       /// \brief Set the CFM  of this joint
      public: void SetCFM(double newERP);

      /// \brief Get the CFM of this joint
      public: double GetCFM();

      protected: btTypedConstraint *constraint;

      protected: btDynamicsWorld *world;
    };

    /// \}
  }
}
#endif


