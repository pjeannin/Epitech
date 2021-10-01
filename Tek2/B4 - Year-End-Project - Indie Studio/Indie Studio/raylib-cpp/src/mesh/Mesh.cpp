#include "Mesh.hpp"

raylib::Mesh::Mesh(::Mesh const &mesh) noexcept
{
    *this = mesh;
}

raylib::Mesh::Mesh(int const VertexCount, int const TriangleCount) noexcept
{
    vertexCount = VertexCount;
    triangleCount = TriangleCount;
}

::Mesh raylib::Mesh::poly(int const sides, float const radius) noexcept
{
    return ::GenMeshPoly(sides, radius);
}

::Mesh raylib::Mesh::plane(float const width, float const length, int const resX, int const resZ) noexcept
{
    return ::GenMeshPlane(width, length, resX, resZ);
}

::Mesh raylib::Mesh::cube(float const width, float const height, float const length) noexcept
{
    return ::GenMeshCube(width, height, length);
}

::Mesh raylib::Mesh::sphere(float const radius, int const rings, int const slices) noexcept
{
    return ::GenMeshSphere(radius, rings, slices);
}

::Mesh raylib::Mesh::hemiSphere(float const radius, int const rings, int const slices) noexcept
{
    return ::GenMeshHemiSphere(radius, rings, slices);
}

::Mesh raylib::Mesh::cylinder(float const radius, float const height, int const slices) noexcept
{
    return ::GenMeshCylinder(radius, height, slices);
}

::Mesh raylib::Mesh::torus(float const radius, float const size, int const radSeg, int const sides) noexcept
{
    return ::GenMeshTorus(radius, size, radSeg, sides);
}

::Mesh raylib::Mesh::knot(float const radius, float const size, int const radSeg, int const sides) noexcept
{
    return ::GenMeshKnot(radius, size, radSeg, sides);
}

::Mesh raylib::Mesh::heightmap(::Image const &heightmap, ::Vector3 const &size) noexcept
{
    return ::GenMeshHeightmap(heightmap, size);
}

::Mesh raylib::Mesh::cubicmap(::Image const &cubicmap, ::Vector3 const &cubeSize) noexcept
{
    return ::GenMeshCubicmap(cubicmap, cubeSize);
}

raylib::Mesh &raylib::Mesh::operator=(::Mesh const &mesh) noexcept
{
    vertexCount = mesh.vertexCount;
    triangleCount = mesh.triangleCount;
    vertices = mesh.vertices;
    texcoords = mesh.texcoords;
    texcoords2 = mesh.texcoords2;
    normals = mesh.normals;
    tangents = mesh.tangents;
    colors = mesh.colors;
    indices = mesh.indices;
    animVertices = mesh.animVertices;
    animNormals = mesh.animNormals;
    boneIds = mesh.boneIds;
    boneWeights = mesh.boneWeights;
    vaoId = mesh.vaoId;
    vboId = mesh.vboId;
    return *this;
}

raylib::Mesh::~Mesh() noexcept
{
    unload();
}

void raylib::Mesh::upload(bool const dynamic) noexcept
{
    ::UploadMesh(this, dynamic);
}

void raylib::Mesh::updateBuffer(int const index, void *data, int const dataSize, int const offset) noexcept
{
    ::UpdateMeshBuffer(*this, index, data, dataSize, offset);
}

void raylib::Mesh::draw(::Material const &material, ::Matrix const &transform) noexcept
{
    ::DrawMesh(*this, material, transform);
}

void raylib::Mesh::drawInstanced(::Material const &material, ::Matrix* transforms, int const instances) noexcept
{
    ::DrawMeshInstanced(*this, material, transforms, instances);
}

bool raylib::Mesh::Export(std::string const &fileName) noexcept
{
    return ExportMesh(*this, fileName.c_str());
}

void raylib::Mesh::unload() noexcept
{
    if (vboId) {
        ::UnloadMesh(*this);
        vboId = NULL;
    }
}

//raylib::BoundingBox raylib::Mesh::boundingBox() const noexcept
//{
//    return ::GetMeshBoundingBox(*this);
//}

raylib::Mesh &raylib::Mesh::Tangents() noexcept
{
    ::MeshTangents(this);
    return *this;
}

raylib::Mesh &raylib::Mesh::binormals() noexcept
{
    ::MeshBinormals(this);
    return *this;
}

raylib::Model raylib::Mesh::loadModelFrom() const noexcept
{
    return static_cast<raylib::Model>(::LoadModelFromMesh(*this));
}
