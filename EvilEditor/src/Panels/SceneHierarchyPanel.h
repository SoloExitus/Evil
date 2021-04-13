#pragma once

#include "Evil/Core/Base.h"
#include "Evil/Core/Log.h"
#include "Evil/Scene/Scene.h"
#include "Evil/Scene/Entity.h"

namespace Evil
{
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}
