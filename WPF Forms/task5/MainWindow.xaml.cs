using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace task5
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        int turn=1;
        int count = 0;

        public void check_turn() { }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            count++;
            if (turn == 1)
            {
                one.Foreground = Brushes.Red;
                one.Content = 'X';
                turn = 2;
                text.Text = "Turn Player 2";
                one.IsEnabled = false;
                check_win();
            }
            else
            {
                one.Foreground = Brushes.Blue;
                one.Content = 'O';
                turn = 1;
                text.Text = "Turn Player 1";
                one.IsEnabled = false;
                check_win();
            }
        }

        private void two_Click(object sender, RoutedEventArgs e)
        {
            count++;
            if (turn == 1)
            {
                two.Foreground = Brushes.Red;
                two.Content = 'X';
                turn = 2;
                text.Text = "Turn Player 2";
                two.IsEnabled = false;
                check_win();
            }
            else
            {
                two.Foreground = Brushes.Blue;
                two.Content = 'O';
                turn = 1;
                text.Text = "Turn Player 1";
                two.IsEnabled = false;
                check_win();
            }
        }

        private void three_Click(object sender, RoutedEventArgs e)
        {
            count++;
            if (turn == 1)
            {
                three.Foreground = Brushes.Red;
                three.Content = 'X';
                turn = 2;
                text.Text = "Turn Player 2";
                three.IsEnabled = false;
                check_win();
            }
            else
            {
                three.Foreground = Brushes.Blue;
                three.Content = 'O';
                turn = 1;
                text.Text = "Turn Player 1";
                three.IsEnabled = false;
                check_win();
            }
        }
        private void five_Click(object sender, RoutedEventArgs e)
        {
            count++;
            if (turn == 1)
            {
                five.Foreground = Brushes.Red;
                five.Content = 'X';
                turn = 2;
                text.Text = "Turn Player 2";
                five.IsEnabled = false;
                check_win();
            }
            else
            {
                five.Foreground = Brushes.Blue;
                five.Content = 'O';
                turn = 1;
                text.Text = "Turn Player 1";
                five.IsEnabled = false;
                check_win();
            }
        }

        private void six_Click(object sender, RoutedEventArgs e)
        {
            count++;
            if (turn == 1)
            {
                six.Foreground = Brushes.Red;
                six.Content = 'X';
                turn = 2;
                text.Text = "Turn Player 2";
                six.IsEnabled = false;
                check_win();
            }
            else
            {
                six.Foreground = Brushes.Blue;
                six.Content = 'O';
                turn = 1;
                text.Text = "Turn Player 1";
                six.IsEnabled = false;
                check_win();
            }
        }

        private void seven_Click(object sender, RoutedEventArgs e)
        {
            count++;
            if (turn == 1)
            {
                seven.Foreground = Brushes.Red;
                seven.Content = 'X';
                turn = 2;
                text.Text = "Turn Player 2";
                seven.IsEnabled = false;
                check_win();
            }
            else
            {
                seven.Foreground = Brushes.Blue;
                seven.Content = 'O';
                turn = 1;
                text.Text = "Turn Player 1";
                seven.IsEnabled = false;
                check_win();
            }
        }

        private void eight_Click(object sender, RoutedEventArgs e)
        {
            count++;
            if (turn == 1)
            {
                eight.Foreground = Brushes.Red;
                eight.Content = 'X';
                turn = 2;
                text.Text = "Turn Player 2";
                eight.IsEnabled = false;
                check_win();
            }
            else
            {
                eight.Foreground = Brushes.Blue;
                eight.Content = 'O';
                turn = 1;
                text.Text = "Turn Player 1";
                eight.IsEnabled = false;
                check_win();
            }
        }

        private void nine_Click(object sender, RoutedEventArgs e)
        {
            count++;
            if (turn == 1)
            {
                nine.Foreground = Brushes.Red;
                nine.Content = 'X';
                turn = 2;
                text.Text = "Turn Player 2";
                nine.IsEnabled = false;
                check_win();
            }
            else
            {
                nine.Foreground = Brushes.Blue;
                nine.Content = 'O';
                turn = 1;
                text.Text = "Turn Player 1";
                nine.IsEnabled = false;
                check_win();
            }
        }

        private void four_Click_1(object sender, RoutedEventArgs e)
        {
            count++;
            if (turn == 1)
            {
                four.Foreground = Brushes.Red;
                four.Content = 'X';
                turn = 2;
                text.Text = "Turn Player 2";
                four.IsEnabled = false;
                check_win();
            }
            else
            {
                four.Foreground = Brushes.Blue;
                four.Content = 'O';
                turn = 1;
                text.Text = "Turn Player 1";
                four.IsEnabled = false;
                check_win();
            }
        }

        public void check_win()
        {
            bool win = false;
            if (one.Content.Equals(two.Content) && one.Content.Equals(three.Content))
            {
                if (one.Content.Equals('X'))
                    text.Text = "Player 1 Wins!";
                else
                    text.Text = "Player 2 Wins!";
                win = true;
            }
            else if (four.Content.Equals(five.Content) && four.Content.Equals(six.Content))
            {
                if (four.Content.Equals('X'))
                    text.Text = "Player 1 Wins!";
                else
                    text.Text = "Player 2 Wins!";
                win = true;
            }
            else if(seven.Content.Equals(eight.Content) && seven.Content.Equals(nine.Content))
            {
                if (seven.Content.Equals('X'))
                    text.Text = "Player 1 Wins!";
                else
                    text.Text = "Player 2 Wins!";
                win = true;
            }
            else if (one.Content.Equals(four.Content) && one.Content.Equals(seven.Content))
            {
                if (one.Content.Equals('X'))
                    text.Text = "Player 1 Wins!";
                else
                    text.Text = "Player 2 Wins!";
                win = true;
            }
            else if (two.Content.Equals(five.Content) && two.Content.Equals(eight.Content))
            {
                if (two.Content.Equals('X'))
                    text.Text = "Player 1 Wins!";
                else
                    text.Text = "Player 2 Wins!";
                win = true;
            }
            else if (three.Content.Equals(six.Content) && three.Content.Equals(nine.Content))
            {
                if (three.Content.Equals('X'))
                    text.Text = "Player 1 Wins!";
                else
                    text.Text = "Player 2 Wins!";
                win = true;
            }
            else if (one.Content.Equals(five.Content) && one.Content.Equals(nine.Content))
            {
                if (one.Content.Equals('X'))
                    text.Text = "Player 1 Wins!";
                else
                    text.Text = "Player 2 Wins!";
                win = true;
            }
            else if (three.Content.Equals(five.Content) && three.Content.Equals(seven.Content))
            {
                if (three.Content.Equals('X'))
                    text.Text = "Player 1 Wins!";
                else
                    text.Text = "Player 2 Wins!";
                win = true;
            }         
            if ((count==9) && (win.Equals(false)))
            {
                text.Text = "Draw ";
                count = 0;
            }
            if (win.Equals(true))
            {
                one.IsEnabled = false;
                two.IsEnabled = false;
                three.IsEnabled = false;
                four.IsEnabled = false;
                five.IsEnabled = false;
                six.IsEnabled = false;
                seven.IsEnabled = false;
                eight.IsEnabled = false;
                nine.IsEnabled = false;
                count = 0;
            }
        }

        private void reset_Click(object sender, RoutedEventArgs e)
        {
            one.IsEnabled = true;
            two.IsEnabled = true;
            three.IsEnabled = true;
            four.IsEnabled = true;
            five.IsEnabled = true;
            six.IsEnabled = true;
            seven.IsEnabled = true;
            eight.IsEnabled = true;
            nine.IsEnabled = true;
            one.Foreground = Brushes.Black;
            two.Foreground = Brushes.Black;
            three.Foreground = Brushes.Black;
            four.Foreground = Brushes.Black;
            five.Foreground = Brushes.Black;
            six.Foreground = Brushes.Black;
            seven.Foreground = Brushes.Black;
            eight.Foreground = Brushes.Black;
            nine.Foreground = Brushes.Black;

            one.Content = "1";
            two.Content = "2";
            three.Content = "3";
            four.Content = "4";
            five.Content = "5";
            six.Content = "6";
            seven.Content = "7";
            eight.Content = "8";
            nine.Content = "9";
            text.Text = "Turn Player 1";
            turn = 1;
            count = 0;
        }
    }
}
