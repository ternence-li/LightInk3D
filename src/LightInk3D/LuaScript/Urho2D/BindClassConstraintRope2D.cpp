

/* Copyright ChenDong(Wilbur), email <baisaichen@live.com>. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "../../Precompiled.h"
#include "../../Urho2D/ConstraintRope2D.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_ConstraintRope2D(LuaModele & lm)
	{
		lm
		[
			LuaRegister<ConstraintRope2D, void ()>(lm.state(), "ConstraintRope2D", BaseClassStrategy<Constraint2D>())
				.disable_new()
				.def(CreateObject<ConstraintRope2D>, "new")
				.def(&ConstraintRope2D::SetOwnerBodyAnchor, "SetOwnerBodyAnchor")
				.def(&ConstraintRope2D::SetOtherBodyAnchor, "SetOtherBodyAnchor")
				.def(&ConstraintRope2D::SetMaxLength, "SetMaxLength")
				.def(&ConstraintRope2D::GetOwnerBodyAnchor, "GetOwnerBodyAnchor")
				.def(&ConstraintRope2D::GetOtherBodyAnchor, "GetOtherBodyAnchor")
				.def(&ConstraintRope2D::GetMaxLength, "GetMaxLength")
				
		];
	}
}