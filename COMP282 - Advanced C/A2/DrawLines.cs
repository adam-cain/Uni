using System.Data;
using System.Windows.Forms;

namespace A2
{
    public partial class DrawLines : Form
    {

        public DrawLines()
        {
            InitializeComponent();
        }

        private void DrawLines_Load(object sender, EventArgs e)
        {

        }

        private void findIntersectButton_Click(object sender, EventArgs e)
        {

        }

        private void colorButton_Click(object sender, EventArgs e)
        {

        }

        private void removeButton_Click(object sender, EventArgs e)
        {

        }

        private void dataGrid_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        List<Line> lines;
        private void dataGrid_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0 && e.RowIndex < dataGrid.Rows.Count)
            {
                lines = new List<Line>();
                for (int j = 0; j < dataGrid.Rows.Count - 1; j++)
                {
                    bool validRow = true;
                    int value;
                    for (int i = 0; i < 4; i++)
                    {
                        if (dataGrid.Rows[j].Cells[i].Value == null)
                        {
                            validRow = false;
                            break;
                        }
                        
                        else if (!int.TryParse(dataGrid.Rows[j].Cells[i].Value.ToString(), out value))
                        {
                            validRow = false;
                            break;
                        }
                    }
                    if (validRow)
                    {
                        Point startP = new Point(int.Parse(dataGrid.Rows[j].Cells[0].Value.ToString()), int.Parse(dataGrid.Rows[j].Cells[1].Value.ToString()));
                        Point endP = new Point(int.Parse(dataGrid.Rows[j].Cells[2].Value.ToString()), int.Parse(dataGrid.Rows[j].Cells[3].Value.ToString()));
                        Color color = (Color)dataGrid.Rows[j].Cells[4].Value;
                        findIntersectButton.Text = color.ToString();
                        Line line = new Line(startP,endP,color);
                        lines.Add(line);
                    }
                }
                canvas.Invalidate();
            }
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.Clear(Color.White); // clear the PictureBox

            Pen pen = new Pen(Color.Black, 2); // create a pen for drawing the lines
            if (lines != null)
            {
                foreach (Line line in lines)
                {
                    findIntersectButton.Text = line.Color.ToString();
                    pen.Color = line.Color; // set the pen color
                    e.Graphics.DrawLine(pen, line.StartPoint, line.EndPoint); // draw the line
                }
            }
        }

        private void dataGrid_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
            if(e.ColumnIndex != 4)
            {
                int value;
                dataGrid.Rows[e.RowIndex].Cells[e.ColumnIndex].ErrorText = "";
                if (e.FormattedValue.ToString() == "")
                {
                    dataGrid.Rows[e.RowIndex].Cells[e.ColumnIndex].ErrorText = "Cell cannot be empty";
                }else if (!int.TryParse(e.FormattedValue.ToString(), out value))
                {
                    dataGrid.Rows[e.RowIndex].Cells[e.ColumnIndex].ErrorText = "Cell must be a valid numeric value.";
                }
            }
        }

        private void dataGridView1_DefaultValuesNeeded(object sender, DataGridViewRowEventArgs e)
        {
            e.Row.Cells["Color"].Value = Color.Black;
        }

    }
}