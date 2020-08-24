#include "RenderCellLayer.h"
#include <GoblinEngine/Window/Platforms/OpenGL/OpenGLShader.h>

#define MAX_TRANSFORMS 2
using namespace GoblinEngine;
void RenderCellLayer::OnAttach()
{
	_transforms = CreateTransforms();

	float vertices[] = {
		 1.0f,  1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f
	};
	auto vertexBuffer = GE_RENDER_API.CreateVertexBuffer(vertices, 12);

	vertexBuffer->SetLayout(Ref<BufferElementsLayout>(
		Ref<BufferElementsLayout>
			(new BufferElementsLayout(
				std::initializer_list<BufferElement> {
					{ "a_Position", GoblinEngine::ShaderDataType::Float3 }
				}
			)
		)
	));

	int indices[] = {
		0, 1, 3,
		1, 2, 3
	};
	auto indexBuffer = GE_RENDER_API.CreateIndexBuffer(indices, 6);

	s_vertexArray = GE_RENDER_API.CreateVertexArray();
	s_vertexArray->AddVertexBuffer(vertexBuffer);
	s_vertexArray->SetIndexBuffer(indexBuffer);

	s_shader.reset(new GoblinEngine::OpenGLShader(
		"C:\\dev\\GoblinEngine\\SandBox\\src\\Shader\\test.vert",
		"C:\\dev\\GoblinEngine\\SandBox\\src\\Shader\\test.frag"));
}

void RenderCellLayer::OnUpdate()
{
	GoblinEngine::Renderer::BeginScene(*s_camera);
	for (size_t i = 0; i < MAX_TRANSFORMS * MAX_TRANSFORMS; i++)
	{
		if (i % 4 == 0)
		{
			s_shader->SetUniformVec3("u_Color", _colorChoose.GetColor1());
		}
		else if (i % 4 == 1)
		{
			s_shader->SetUniformVec3("u_Color", _colorChoose.GetColor2());
		}
		else if (i % 4 == 2)
		{
			s_shader->SetUniformVec3("u_Color", _colorChoose.GetColor3());
		}
		else
		{
			s_shader->SetUniformVec3("u_Color", _colorChoose.GetColor4());
		}

		GoblinEngine::Renderer::Submit(*s_vertexArray, *s_shader, _transforms[i].GetWorldMatrix());
	}
	GoblinEngine::Renderer::EndScene();
}

void RenderCellLayer::OnDetach()
{
}

GoblinEngine::Transform* RenderCellLayer::CreateTransforms()
{
	auto* result = new GoblinEngine::Transform[MAX_TRANSFORMS * MAX_TRANSFORMS];

	for (size_t i = 0; i < MAX_TRANSFORMS; i++)
	{
		for (size_t j = 0; j < MAX_TRANSFORMS; j++)
		{
			int index = i * MAX_TRANSFORMS + j;
			result[index].SetPosition(glm::vec3(j * 0.1f, i * 0.1f, 0));
			result[index].SetScale(glm::vec3(0.4f));
		}
	}

	return result;
}