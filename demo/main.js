const {
  Color,
  Graph,
  GraphAttributes,
  GraphIO,
  NodeList,
  Shape,
  randomGraph
} = window.ogdf
const {
  BalloonLayout,
  // BertaultLayout,
  CircularLayout,
  // ComponentSplitterLayout,
  DavidsonHarelLayout,
  // DominanceLayout,
  FastMultipoleEmbedder,
  // FastMultipoleMultilevelEmbedder,
  FMMMLayout,
  PlanarizationLayout,
  SugiyamaLayout,
  TreeLayout,
  TutteLayout
  // UpwardPlanarizationLayout
  // VisibilityLayout
} = window.ogdf
const {
  nodeGraphics,
  nodeStyle,
  edgeGraphics,
  edgeStyle
} = GraphAttributes

const layoutMethods = {
  balloon: BalloonLayout,
  // bertault: BertaultLayout,
  circular: CircularLayout,
  // componentSplitter: ComponentSplitterLayout,
  davidsonHarel: DavidsonHarelLayout,
  // dominanceLayout: DominanceLayout,
  fastMultipoleEmbedder: FastMultipoleEmbedder,
  // fastMultipoleMultilevelEmbedder: FastMultipoleMultilevelEmbedder,
  fmmm: FMMMLayout,
  planarization: PlanarizationLayout,
  sugiyama: SugiyamaLayout,
  tree: TreeLayout,
  tutte: TutteLayout
  // upwardPlanarization: UpwardPlanarizationLayout
  // visibility: VisibilityLayout
}

const randomColor = () => {
  return new Color(
    Math.floor(Math.random() * 255),
    Math.floor(Math.random() * 255),
    Math.floor(Math.random() * 255),
    255
  )
}

Object.keys(layoutMethods).forEach((layoutName) => {
  const option = document.createElement('option')
  option.innerHTML = layoutName
  document.getElementById('layout').appendChild(option)
})

document.getElementById('button').addEventListener('click', () => {
  const graph = new Graph()
  const n = +document.getElementById('n').value
  const m = +document.getElementById('m').value
  randomGraph(graph, n, m)

  const attributes = new GraphAttributes(graph, nodeGraphics | edgeGraphics | nodeStyle | edgeStyle)
  const nodes = new NodeList()
  graph.allNodes(nodes)
  for (let i = 0; i < nodes.size(); ++i) {
    const node = nodes.at(i)
    attributes.setWidth(node, 10)
    attributes.setHeight(node, 10)
    attributes.setShape(node, Shape.Ellipse)
    attributes.setFillColor(node, randomColor())
  }
  const layout = new layoutMethods[document.getElementById('layout').value]()
  layout.call(attributes)

  const svg = GraphIO.getSVG(attributes)
  const img = document.getElementById('display')
  img.src = `data:image/svg+xml;base64,${window.btoa(svg)}`
})
